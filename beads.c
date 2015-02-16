/*

Broken Necklace

You have a necklace of N red, white, or blue beads (3<=N<=350) some of which are red, others blue, and others white, arranged at random. Here are two examples for n=29:

                1 2                               1 2
            r b b r                           b r r b
          r         b                       b         b
         r           r                     b           r
        r             r                   w             r
       b               r                 w               w
      b                 b               r                 r
      b                 b               b                 b
      b                 b               r                 b
       r               r                 b               r
        b             r                   r             r
         b           r                     r           r
           r       r                         r       b
             r b r                             r r w
            Figure A                         Figure B
                        r red bead
                        b blue bead
                        w white bead
The beads considered first and second in the text that follows have been marked in the picture.

The configuration in Figure A may be represented as a string of b's and r's, where b represents a blue bead and r represents a red one, as follows: brbrrrbbbrrrrrbrrbbrbbbbrrrrb .

Suppose you are to break the necklace at some point, lay it out straight, and then collect beads of the same color from one end until you reach a bead of a different color, and do the same for the other end (which might not be of the same color as the beads collected before this).

Determine the point where the necklace should be broken so that the most number of beads can be collected.

Example

For example, for the necklace in Figure A, 8 beads can be collected, with the breaking point either between bead 9 and bead 10 or else between bead 24 and bead 25.

In some necklaces, white beads had been included as shown in Figure B above. When collecting beads, a white bead that is encountered may be treated as either red or blue and then painted with the desired color. The string that represents this configuration can include any of the three symbols r, b and w.

Write a program to determine the largest number of beads that can be collected from a supplied necklace.

PROGRAM NAME: beads

INPUT FORMAT

Line 1:	N, the number of beads
Line 2:	a string of N characters, each of which is r, b, or w
SAMPLE INPUT (file beads.in)

29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
OUTPUT FORMAT

A single line containing the maximum of number of beads that can be collected from the supplied necklace.
SAMPLE OUTPUT (file beads.out)

11
OUTPUT EXPLANATION

Consider two copies of the beads (kind of like being able to runaround the ends). The string of 11 is marked.
                Two necklace copies joined here
                             v
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb|wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
                       ******|*****
                       rrrrrb bbbbb  <-- assignments
                       5 x r  6 x b  <-- 11 total

*/

/*
ID: ALVERPhysicist
LANG: C
TASK: beads
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int all_the_same(char x[]){

	char a;
	int i;
	int c = 1;
	
	for(i=0; i<strlen(x)-1; ++i){
	
		if(x[i] == x[i+1]){
		
			c++;
		}
		else
			break;
	}
	
	if(c == strlen(x))
		return 1;
	else
		return 0;
}
	
		


main() {

	FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");
    
    int n, i, max_en = 0, c = 0, flag, last = 0;
    char necklace[351];
   	char* round;
   	char x;
    
    fscanf(fin, "%d", &n);
    fscanf(fin, "%s", necklace);
    
    //First lets look at the complete picture
    
    if(all_the_same(necklace)){     //If the necklace has all the same color beans
    
    	c = 0;
    }
    else{
    
    	for(i=0; i<strlen(necklace); ++i){    // Here is not necessary
    
    		if(necklace[i] == 'w'){
    	
    			c++;
    			continue;
    		}
    	
    		x = necklace[i];
    	
    		while(x == necklace[i] || necklace[i] == 'w'){
    		
    			++i;
    			++c;
    		}
    		break;
    	}
    }
    
    //printf("c :: %d\n", c);
        
    round = (char*)malloc(sizeof(char)*(strlen(necklace)+1+c));
    
    strcpy(round, necklace);
    if(c != 0)
    	strncat(round, necklace, c);
    
    //printf("%s   len :: %d\n", round, strlen(round));
    
    i=0;
    
    while(round[i]){
    
    	i = last;
    	c = 0;
    	flag = 0;
    	
    	while((round[i] == 'w') && round[i] && c<strlen(necklace)){
    	    
    		++i;
    		++c;	
    	}
    	
    	x = round[i];
    	
    	while((round[i] == x || round[i] == 'w') && round[i] && c<strlen(necklace)){
    	
    		if(round[i] == 'w' && flag == 0){
    			
    			last = i;
    			flag = 1;
    		}
    	
    		++i;
    		c++;
    	}
    	
    	while((round[i] != x) && round[i] && c<strlen(necklace)){
    	
    		if(flag == 0){
    		
    			last = i;
    			flag = 1;
    		}
    	
    		++i;
    		c++;
    	}
    	
    	if(c > max_en)
    		max_en = c;
    	
    	//printf("c :%d i :%d\n", c, i); 
    }
    
    fprintf(fout, "%d\n", max_en);
   
   	exit(0);
   	
}
    
    
    
