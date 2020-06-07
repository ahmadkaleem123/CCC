#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


bool a;
int i;
int j;
int b;
int nums[1000];
int t;
int c;
int d;
int e;
int z;
int p1;
int p2;
int ind = 0;
bool isPrime(int x)
{
	for( i = 2; i<x; i++) {
		if(x % i == 0){
			return false;
			break;
		}
		else if(i == x-1){
			return true;
		}
	}
}

int nextPrime(int y)
{
	if(y == 2){
		return 3;
	}
	else{
		y = y+2;
		while(! isPrime(y)){
			y = y+2;
		}
		return y;
	}
}
	
int main(){
	scanf("%d", &t);
	for(i = 0;i < t; i++){
		scanf("%d", &c);
		nums[i] = c;
	}
	for(j=0; j<t; j++){
		d = nums[j];	
		d = d * 2;
		p1 = 2;
		ind = 0;
		while(ind == 0){
			p2 = d-p1;
			if(isPrime(p2)){
				printf("%d ", p1);
				printf(" %d\n", p2);
				ind = 1;
			}
			else{
				p1 = nextPrime(p1);
			}
		}
		
	}
}




