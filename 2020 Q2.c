#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int M;
int N;
int i;
int j;
int k;
int y;
int a;
int end[2]; 
int b[2];
int room[1001][1001];
int factors[500000][2];
int complete = 0;
bool ans;
int s = 0;
int findfactors(int x){
	k = 0;
	for(i = 1; i<(x/2);i++){
		if(x % i == 0){
			factors[k][0] = i;
			factors[k][1] = x/i;
			factors[k+1][0] = x/i;
			factors[k+1][1] = i;
			k = k+2;
		}
	}
}

bool escape(int pos[]){
	int c[500000][2];
	int l;
	int z;
	int t[2];
	if(pos[0] == M && pos[1] == N){
		complete = 1;
	}
	printf("%d   %d", pos[0], pos[1]);
	if(complete == 1){
		return true;
		printf("Done!\n");
	}
	a = room[pos[0]][pos[1]];
	findfactors(a);
	for(z = 0; z<k;z++){
		c[z][0] = factors[z][0];
		c[z][1] = factors[z][1];
	}
	l = k;
	for(z = 0; z<l;z++){
		t[0] = c[z][0];
		t[1] = c[z][1];
		escape(t);
	}	 
	

}
void escape2(int pos[]){        
	int l;
	int z;
	int d;
	int c[1000][2];
	int t[2];
	z = 0;
	if(pos[0] == 1 && pos[1] == 1){
		complete = 1;
	}
	if(complete == 0){
		l = pos[0] * pos[1];
		for(i = 1; i<=M; i++){
			for(j = 1; j<=N; j++){
				if(room[i][j] == l){
					c[z][0] = i;
					c[z][1] = j;
					z++;
				}
			}
		}
		if(z == 0 || s > 100){
			s = 0;
		}
		else{
			for(d=0;d<z+1;d++){
				t[0] = c[d][0];
				t[1] = c[d][1];
				s++;
				escape2(t);
				s = 0;
			}
		}
	} 
	
}


int main (void){
	scanf("%d", &M);
	scanf("%d", &N);
	for(i = 1; i<M+1; i++){
		for(j = 1; j<N+1; j++){
			scanf("%d", &room[i][j]);
		}
	}
	end[0] = M;
	end[1] = N;
	escape2(end);
	if(complete == 1){
		printf("yes");
	}
	else{
		printf("no");
	}
	/*findfactors(80);
	b[0] = factors[0][0];
	b[1] = factors[0][1];*/
	
}





