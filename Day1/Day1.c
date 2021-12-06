#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
	int input[10000];
	int length = 0;
	int total = 0;
	int j = 0;
	int A[3];
	int B[3];
	int aStart = 0;
	int aSum = 0;
	int bSum = 0;


	FILE *fp = fopen("Day1Input.txt", "r");
	if(fp == NULL){
		exit(1);
	}

	while(fscanf(fp, "%d", &input[j]) != EOF){
		length++;
		j++;
	}

	/*for(int i = 1; i < length; i++){
		if(input[i] > input[i-1]){
			total++;
		}
	}*/

 //computing differences in windows
	for(int i = 0; i < length; i++){
		if(i == 0){//window A begins before B
			A[0] = input[i];
			A[1] = input[i + 1];
			A[2] = input[i + 2];
			aSum = A[0] + A[1] + A[2];
		}
		if(i == 1){
			B[0] = input[i];
			B[1] = input[i + 1];
			B[2] = input[i + 2];
			bSum = B[0] + B[1] + B[2];
		}

		if(i == aStart + 2){ //if end of A window is found
			if(bSum > aSum){ 
				total++; //increment if B window's sum > A window's sum
			}

			aStart = i; //create new windows with new start
			A[0] = input[i];
			A[1] = input[i + 1];
			A[2] = input[i + 2];
			aSum = A[0] + A[1] + A[2];

			if(aSum > bSum){ //compare new A with old B before changing B
				total++;
			}
			
			B[0] = input[i + 1];
			B[1] = input[i + 2];
			B[2] = input[i + 3];
			bSum = B[0] + B[1] + B[2];
		}

	}
	printf("%d\n", total);
	fclose(fp);
}