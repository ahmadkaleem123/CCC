#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int num[3][3];
int filled[3][3];
char sample[3000000];
char num1[1000000];
char num2[1000000];
char num3[1000000];
int x;
int i;
int j;
int a;
int b;
int c;
int d;
int e;
int y;
int m;
int n;
int full;
bool comp = false;
int count = 0;
int sum1[3] = {0,0,0};
int sum2[3] = {0,0,0};
int temp[3];
int findSum1(int m[3][3]){                     /* Finds the number of non X elements in each row*/
	sum1[0] = 0;
	sum1[1] = 0;
	sum1[2] = 0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			sum1[i] = sum1[i] + m[i][j];
		}
	}
}

int findSum2(int m[3][3]){                     /* Finds the number of non X elements in each column*/
	sum2[0] = 0;
	sum2[1] = 0;
	sum2[2] = 0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			sum2[i] = sum2[i] + m[j][i];
		}
	}
}


int findrc(int m[]){                      /* Finds rows and columns to complete*/
	for(i = 0; i<3; i++){
		if(m[i] == 2){
			return i;
			break;
		}
	}
}

int completerow(int m){                 /* Completes mth row of num so that the numbers are in an arithmetic sequence. Note that this function only works when two terms are present.  */
	for(i = 0; i<3;i++){
		temp[i] = num[m][i];
	}
	if(temp[0] <= 1000000 && temp[1] <= 1000000){
		temp[2] = temp[1] + temp[1] - temp[0];
	}
	else if(temp[1] <= 1000000 && temp[2] <= 1000000){
		temp[0] = temp[1] - temp[2] + temp[1];
	}
	else if(temp[0] <= 1000000 && temp[2] <= 1000000){
		temp[1] = (temp[0] + temp[2])/2;
	}  
	for(i = 0; i<3;i++){
		num[m][i] = temp[i];
	}
}

int completecolumn(int m){                 /* Completes mth column of num so that the numbers are in an arithmetic sequence. Note that this function only works when two terms are present.  */
	for(i = 0; i<3;i++){
		temp[i] = num[i][m];
	}
	if(temp[0] <= 1000000 && temp[1] <= 1000000){
		temp[2] = temp[1] + temp[1] - temp[0];
	}
	else if(temp[1] <= 1000000 && temp[2] <= 1000000){
		temp[0] = temp[1] - temp[2] + temp[1];
	}
	else if(temp[0] <= 1000000 && temp[2] <= 1000000){
		temp[1] = (temp[0] + temp[2])/2;
	}  
	for(i = 0; i<3;i++){
		num[i][m] = temp[i];
	}
}

int fill(int m[3][3]){                   /* makes filled array*/
	for(i=0; i<3;i++){
		for(j=0;j<3;j++){
			if(m[i][j] < 1000001){
				filled[i][j] = 1;
			}
			else{
				filled[i][j] = 0;
			}
		}
	}	     
} 
	

bool complete(int m[], int n[]){           /* Function to check if grid has been completed*/
	full = 0;
	for(i = 0; i<3; i++){
		if(m[i] < 3){
			return false;
			break;
			full = 1;
		}
	}
	for(i = 0; i<3; i++){
		if(n[i] < 3){
			return false;
			break;
			full = 1;
		}
	}
	if(full == 0){
		return true;
	}
}
int main() {
	for(j=0;j<3;j++){
		gets(sample);
	    x = strlen(sample);
	    for (i=0; i<x; i++){
			if(sample[i] == ' '){
				if(count == 0){
					a = i;
					count++;
				}
				else if(count == 1){
					b = i;
					count++;
				}
			}
		
	    }
		count = 0;
		c = 0;
		while(c < a) {
			num1[c] = sample[c];
			c++;
		}
		c = a+1;
		while(c < b) {
			num2[c-a-1] = sample[c];
			c++;
		}
		c = b+1;
		while(c < x) {
			num3[c-b-1] = sample[c];
			c++;
		}
		if(num1[0] == 'X'){
			num[j][0] = 10000001;
		}
		else{
	   		y = atoi(num1);
			num[j][0] = y;
		}
		if(num2[0] == 'X'){
			num[j][1] = 10000001;
		}
		else{
	   		y = atoi(num2);
			num[j][1] = y;
		}
		if(num3[0] == 'X'){
			num[j][2] = 10000001;
		}
		else{
	   		y = atoi(num3);
			num[j][2] = y;
		}	 
	}
	fill(num);
	findSum1(filled);
	findSum2(filled);
	comp = complete(sum1, sum2);
	while(!comp){
		d = findrc(sum1);
		if(d<3){
			completerow(d);
		}
		fill(num);
		findSum1(filled);
		findSum2(filled);
		d = findrc(sum2);
		if(d<3){
			completecolumn(d);
		}
		fill(num);
		findSum1(filled);
		findSum2(filled);
		comp = complete(sum1, sum2);
	}
	printf("\n");
	for(i = 0; i<3;i++){
		for(j=0;j<3;j++){
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
}	 

