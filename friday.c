/*

Friday the Thirteenth
Is Friday the 13th really an unusual event?

That is, does the 13th of the month land on a Friday less often than on any other day of the week? To answer this question, write a program that will compute the frequency that the 13th of each month lands on Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, and Saturday over a given period of N years. The time period to test will be from January 1, 1900 to December 31, 1900+N-1 for a given number of years, N. N is positive and will not exceed 400.

Note that the start year is NINETEEN HUNDRED, not 1990.

There are few facts you need to know before you can solve this problem:

January 1, 1900 was on a Monday.
Thirty days has September, April, June, and November, all the rest have 31 except for February which has 28 except in leap years when it has 29.
Every year evenly divisible by 4 is a leap year (1992 = 4*498 so 1992 will be a leap year, but the year 1990 is not a leap year)
The rule above does not hold for century years. Century years divisible by 400 are leap years, all other are not. Thus, the century years 1700, 1800, 1900 and 2100 are not leap years, but 2000 is a leap year.
Do not use any built-in date functions in your computer language.

Don't just precompute the answers, either, please.

PROGRAM NAME: friday

INPUT FORMAT

One line with the integer N.
SAMPLE INPUT (file friday.in)

20
OUTPUT FORMAT

Seven space separated integers on one line. These integers represent the number of times the 13th falls on Saturday, Sunday, Monday, Tuesday, ..., Friday.
SAMPLE OUTPUT (file friday.out)

36 33 34 33 35 35 34

*/

/*
ID: ALVERPhysicist
LANG: C
TASK: friday
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leap_checker(int year){  // Checks whether the year is a leap year

	int flag=0;

	if((year)%100 == 0){ // For centuries
		
		if((year)%400 == 0){
			
			// It's a leap year
			flag=1;
		}
	}
	else{
			
		if((year)%4 == 0){
			
			//It's a leap year
			flag=1;
		}
	}
	
	return flag;
}


main() {

	FILE *fin = fopen("friday.in", "r");
	FILE *fout = fopen("friday.out", "w");

	int mountdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int mountdays_leap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int* year_p;
	int days[] = {0, 0, 0, 0, 0, 0, 0};
	int n, days_sum_n=0, i, j, flag, x=0, ind;
	
	fscanf(fin, "%d", &n);
	
	for(i=0; i<n; ++i){
	
		year_p = mountdays;
	
		flag = leap_checker(1900+i);
		
		if(flag == 1){
		
			year_p = mountdays_leap;
		}
		
		for(j=0; j<12; ++j){
		
			ind = (x + 13)%7 -1;    //This is the index in the week 
			
			if(ind == -1){
			
				ind += 7;
			}
			
			days[ind]++;
			x += year_p[j];
		}
	}
	
	fprintf(fout, "%d %d ", days[5], days[6]);
	
	for(i=0; i<5; ++i){
	
		if(i<4)
			fprintf(fout, "%d ", days[i]);
		else
			fprintf(fout, "%d\n", days[i]);
	}
	
	exit(0);
}
	
	
	
	
	
	
	
		 

