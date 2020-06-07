#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int letters[26];
char N[200000];
char H[200000];
/*char *done[];*/
char curr[];
int temp[26];
char done[][500];
char blah[] = "zzz";
char X[];
char q[];
int s = 0;
int x;
int y;
int i;
int j;
int k;
int d = 0;
int m;
int n = 1;
int l;
int T = 1;
int P = 0;
int z;
/*bool repeat(){
	int t = 1;
	int p = 0;
	for(i = 0; i<d;i++){
		for(l = 0; l<strlen(done[i]);l++){
			if(done[i][l] != curr[l]){
				t = 0;
			}
		}
		if(t == 1){
			p = 1;
			break;
		}
		else{
			t = 1;
		}
	}
	if(p == 0){
		return false;
	}
	else{
		return true;
	}
	
	
}*/

bool repeat(){
	int t;
	int p = 0;
	for(i = 0; i<d;i++){
		t = strcmp(curr, done[i]);
		if(t == 0){
			p = 1;
			return true;
		}
	}
	if(p == 0){
		return false;
	}
	/* instead of multiple lines just have one variable and keep adding to that.*/
	
}
/*
bool repeat(){
	int t = 1;
	int p = 0;
	for(i = 0; i<d;i++){
		for(l = 0; l<z; l++){
			if(X[(z*i)+l] != curr[l]){
				t = 0;
			}
		}
		if(t == 1){
			p = 1;
			break;
		}
		else{
			t = 1;
		}
	}
	if(p == 1){
		return true;
	}
	else{
		return false;
	}
}*/

/*bool repeat(){
	int t;
	int p = 0;
	for(i = 0; i<d;i++){
		for(l = 0; l<z; l++){
			q[l] = X[(z*i)+l];
		}
		t = strcmp(q, curr);
		if(t == 0){
			p = 1;
			break;
		}
	}
	if(p == 1){
		return true;
	}
	else{
		return false;
	}
}*/
	


int main (void) {
	for(i = 0; i<25;i++){
		letters[i] = 0;
	}
	scanf("%s", N);
	scanf("%s", H);
	/*z = strlen(N);*/
	if(strlen(N) <= strlen(H)){
		for(i=0;i<strlen(N);i++){
			x = N[i] - 97;
			letters[x] = letters[x] + 1;
		}
		/*for(i = 0; i<26;i++){
			printf("%d", letters[i]);
		}
		printf("\n");*/
		for(j=0; j<=(strlen(H)-strlen(N)); j++){
			memset(curr, 0, strlen(curr));
			for(i = 0; i<26;i++){
				temp[i] = 0;
			}
			for(k=0; k<strlen(N);k++){
				curr[k] = H[j+k];
			}
			/*printf("%s\n", curr);
			if(repeat()){
				printf("Repeat!\n");
			}
			else{
				printf("Not repeat!\n");
			}*/
			if(!repeat()){
				for(i=0;i<strlen(curr);i++){
					x = curr[i] - 97; 
				    temp[x] = temp[x] + 1;
				}
				for(i = 0; i<26; i++){
					if(temp[i] != letters[i] && letters[i] < 200000){
						n = 0;
						/*printf("%d\n", i);
						printf("%d\n", temp[i]);
						printf("%d\n", letters[i]);*/
						break;
					}
				}
				/*for(i = 0; i<26;i++){
					printf("%d", temp[i]);
				}
				printf("\n");
				for(i = 0; i<26;i++){
					printf("%d", letters[i]);
				}*/
				/*printf("\n");*/
				if(n == 1){
					/*for(i = 0; i<strlen(curr);i++){
						/*X[s] = curr[i];*/
						/*done[d][i] = curr[i];*/
						/*strcpy(done[d], curr);ffffff*/
						/*s++;
					}*/
					strcpy(done[d], curr);
					/*done[d] = curr;*/
					/*printf("%d\n", strlen(done[d]));*/
					/*printf("%s\n", done[d]);*/
					/*printf("%s\n", curr);*/
					d++;
				}
				else{
					n = 1;
				}
				
			}
		
		
		}
	}
	printf("%d\n", d);
	/*for(i = 0; i<26;i++){
			printf("%d", letters[i]);
	}*/
	/*for(i = 0; i<s;i++){
		printf("%c", X[i]);
	
	}*/
	/*	
	   
	if(repeat(blah)){
		printf("True");
	}
	done[1] = blah;
	printf("%s", done[1]);
	
	curr[0] = 'a';
	curr[1] = 'b';
	curr[2] = 'c';
	memset(curr, 0, strlen(curr));
	curr[0] = 'z';
	curr[1] = 'y';
	done[1] = curr;
	printf("%d", strlen(curr));
	printf("%s", done[1]);*/

}



