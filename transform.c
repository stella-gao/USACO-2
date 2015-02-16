/*

Transformations
A square pattern of size N x N (1 <= N <= 10) black and white square tiles is transformed into another square pattern. Write a program that will recognize the minimum transformation that has been applied to the original pattern given the following list of possible transformations:

#1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.
#2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.
#3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.
#4: Reflection: The pattern was reflected horizontally (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).
#5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3).
#6: No Change: The original pattern was not changed.
#7: Invalid Transformation: The new pattern was not obtained by any of the above methods.
In the case that more than one transform could have been used, choose the one with the minimum number above.

PROGRAM NAME: transform

INPUT FORMAT

Line 1:	A single integer, N
Line 2..N+1:	N lines of N characters (each either `@' or `-'); this is the square before transformation
Line N+2..2*N+1:	N lines of N characters (each either `@' or `-'); this is the square after transformation
SAMPLE INPUT (file transform.in)

3
@-@
---
@@-
@-@
@--
--@
OUTPUT FORMAT

A single line containing the the number from 1 through 7 (described above) that categorizes the transformation required to change from the `before' representation to the `after' representation.
SAMPLE OUTPUT (file transform.out)

1

*/

/*
ID: ALVERPhysicist
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** reflection_finder(char** grid, int n){

	int i, j;
	char** p;
	char* tem;
	
	p = (char**)malloc(sizeof(char*)*n);
	
	for(i=0; i<n; ++i){
	
		tem = (char*)malloc(sizeof(char)*n);
		for(j=0; j<n; ++j){
		
			tem[j] = grid[i][n-j-1];
		}
		p[i] = tem;
	}
	
	return p;
}

char** mat_copier(char grid[][11], int n){   // Just a matrix copier

	int i, j;
	char **p;
	char* tem;
	
	p = (char**)malloc(sizeof(char*)*n);
	
	for(i=0; i<n; ++i){
		
		tem = (char*)malloc(sizeof(char)*n);
		for(j=0 ;j<n; ++j){
		
			tem[j] = grid[i][j];
		}
		p[i] = tem;
	}
	
	return p;
}

int checker(char** p, char after[][11], int n){  //Grid equality checker

	int i, j, flag=0;
	
	for(i=0; i<n; ++i){
	
		for(j=0; j<n; ++j){
			
			if(p[i][j] != after[i][j])
				flag = 1;
		}
	}
	
	if(flag == 0)
		return 1;
	
	else
		return 0;
}

char** ninety_degree_conv(char** before, int n){  // In order to convert the shape 90 degrees

	char** p;
	char* tem;
	int i, j;	
	
	p = (char**)malloc(sizeof(char*)*n);
	
	for(i=0; i<n; ++i){
	
		tem = (char*)malloc(sizeof(char)*(n));
		for(j=0; j<n; ++j){
		
			tem[j] = before[n-j-1][i];
		}
		p[i] = tem;
	}
	
	return p;
}

main(){

    FILE *fin  = fopen ("transform.in", "r");
    FILE *fout = fopen ("transform.out", "w");
    
    int n, i, j, no, flag = 0;
    char grid_Before[11][11], grid_After[11][11];
    char **p;
    
    fscanf(fin, "%d", &n);
    
    for(i=0; i<n; ++i){  //Grid Before
   
    	fscanf(fin, "%s", grid_Before[i]);
    }
    
    for(i=0; i<n; ++i){ // Grid After
    
    	fscanf(fin, "%s", grid_After[i]);	
    }
   
 	p = mat_copier(grid_Before, n);
   
    for(i=1; i<7; ++i){ // This deals with 1,2,3,6
    
    	p = ninety_degree_conv(p, n);
    	no = checker(p, grid_After, n);
    	if(no){
    	
    		fprintf(fout, "%d\n", i);
    		exit(0);
    	}
    	if(i == 3)
    		i += 2;
    }
    
    // If the minumum transformation is not above we continue with #4 -> Reflection
    
    p = reflection_finder(p, n);
    no = checker(p, grid_After, n);
    if(no){
    
    	fprintf(fout, "%d\n", 4);
    	exit(0);
    }
    
    for(i=1; i<4; ++i){ // This deals 5
    
    	p = ninety_degree_conv(p, n);
    	no = checker(p, grid_After, n);
    	if(no){
    	
    		fprintf(fout, "%d\n", 5);
    		exit(0);
    	}
    }
    
    fprintf(fout, "%d\n", 7);
    
    exit(0);
}
    
    
