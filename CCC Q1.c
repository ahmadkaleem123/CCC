#include <stdio.h>
#include <string.h>
#include <math.h>

int grid[2][2] = {{1,2},{3,4}};
char flip[1000001];
int a;
int i;
int temp;
int temp2;
int main () {
	/*printf("Please provide the input string. \n");*/
	scanf("%s", flip);
	a = strlen(flip);
	for(i = 0; i<a;i++){
		if(flip[i] == 'H'){
			temp = grid[0][0];
			temp2 = grid[1][0];
			grid[0][0] = temp2;
			grid[1][0] = temp;
			temp = grid[0][1];
			temp2 = grid[1][1];
			grid[0][1] = temp2;
			grid[1][1] = temp;
		}
		else if(flip[i] == 'V'){
			temp = grid[0][0];
			temp2 = grid[0][1];
			grid[0][0] = temp2;
			grid[0][1] = temp;
			temp = grid[1][0];
			temp2 = grid[1][1];
			grid[1][0] = temp2;
			grid[1][1] = temp;
		}
	}
	/*printf("Final grid orientation: \n");*/
	printf("%d %d \n", grid[0][0], grid[0][1]);
	printf("%d %d \n", grid[1][0], grid[1][1]);
}

