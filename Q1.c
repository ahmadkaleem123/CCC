#include <string.h>
#include <stdio.h>
#include <math.h>
int i;
int j;
float times[100000];
float pos[100000];
int n;
float speed = 0.0;
float temp;
int main (void) {
	scanf("%d", &n);
	for(i = 0; i<n; i++){
		scanf("%f", &times[i]);
		scanf("%f", &pos[i]);
	}
	for (i = 0; i<n; i++){
		for(j = i+1; j<n; j++){
			temp = fabs((pos[j]-pos[i])/(times[j] - times[i]));
			if(temp > speed){
				speed = temp;
			}
		}
	}
	printf("%f", speed);
    return 0; 
}

