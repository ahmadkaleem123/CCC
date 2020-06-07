#include <string.h>
#include <stdio.h>
#include <math.h>
int i;
int j;
double times[100000];
double pos[100000];
int n;
double speed = 0.0;
double temp;
int main (void) {
	scanf("%d", &n);
	for(i = 0; i<n; i++){
		scanf("%lf", &times[i]);
		scanf("%lf", &pos[i]);
	}
	/*for(i = 0; i<n; i++){
		printf("%f ", times[i]);
		printf("%f\n", pos[i]);
	}*/
	for (i = 0; i<n; i++){
		for(j = i+1; j<n; j++){
			temp = fabs((pos[j]-pos[i])/(times[j] - times[i]));
			if(temp > speed){
				speed = temp;
			}
		}
	}
	printf("%lf", speed);
    return 0; 
}

