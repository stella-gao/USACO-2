/*

Milking Cows
Three farmers rise at 5 am each morning and head for the barn to milk three cows. The first farmer begins milking his cow at time 300 (measured in seconds after 5 am) and ends at time 1000. The second farmer begins at time 700 and ends at time 1200. The third farmer begins at time 1500 and ends at time 2100. The longest continuous time during which at least one farmer was milking a cow was 900 seconds (from 300 to 1200). The longest time no milking was done, between the beginning and the ending of all milking, was 300 seconds (1500 minus 1200).

Your job is to write a program that will examine a list of beginning and ending times for N (1 <= N <= 5000) farmers milking N cows and compute (in seconds):

The longest time interval at least one cow was milked.
The longest time interval (after milking starts) during which no cows were being milked.
PROGRAM NAME: milk2

INPUT FORMAT

Line 1:	The single integer
Lines 2..N+1:	Two non-negative integers less than 1,000,000, respectively the starting and ending time in seconds after 0500
SAMPLE INPUT (file milk2.in)

3
300 1000
700 1200
1500 2100

OUTPUT FORMAT

A single line with two integers that represent the longest continuous time of milking and the longest idle time.
SAMPLE OUTPUT (file milk2.out)

900 300

*/

/*
ID: ALVERPhysicist
LANG: C
TASK: milk2
*/

#include <stdio.h>
#include <stdlib.h>

void sorter(int bone1[], int bone2[], int n){ // Actually a bubble sorter

	int ind, i, swap;
	
	while(n > 0){
	
		ind = 0;
		
		for(i=1; i<n; ++i){
		
			if(bone1[i-1] > bone1[i]){
			
				swap = bone1[i];
				bone1[i] = bone1[i-1];
				bone1[i-1] = swap;
				
				swap = bone2[i];
				bone2[i] = bone2[i-1];
				bone2[i-1] = swap;
				
				ind = i; // The last i is being saved
			}
			
		}
		
		n = ind;
	}
}




main(){

	FILE *fin  = fopen ("milk2.in", "r");
    FILE *fout = fopen ("milk2.out", "w");

	int n, i, start, end, milk, stop = 0;
	int* bone1;
	int* bone2;
	
	fscanf(fin, "%d", &n);
	
	bone1 = (int*)malloc(sizeof(int)*n);
	bone2 = (int*)malloc(sizeof(int)*n);
	
	for(i=0; i<n; ++i){

		fscanf(fin, "%d %d", &bone1[i], &bone2[i]);
	}
	/*
	for(i=0; i<n; ++i){
	
		printf("%d %d\n", bone1[i], bone2[i]);
	} 
	*/
	sorter(bone1, bone2, n); // To sort bone1
	/*
	for(i=0; i<n; ++i){
	
		printf("%d %d\n", bone1[i], bone2[i]);
	}
	*/
	
	start = bone1[0];
	end = bone2[0];
	milk = end - start;
	
	for(i=1; i<n; ++i){
	
		if(bone1[i] <= end && end <=bone2[i]){
		
			end = bone2[i];
			
			if(end - start > milk)
				milk = end -start;
		}
		
		if(bone1[i] > end){
		
			if(end - start > milk)
				milk = end -start;
				
			if(bone1[i] - end > stop)
				stop = bone1[i] - end;
				
			start = bone1[i];
			end = bone2[i];
		}
	}
	
	fprintf(fout, "%d %d\n", milk, stop);
	

	exit(0);
}
