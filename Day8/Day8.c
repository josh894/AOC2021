#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
	FILE *fp = fopen("Day8Input.txt", "r");
	if(fp == NULL){
		exit(1);
	}
	char decode[10][10];
	char wires[10][50];
	char digits[400][100];
	int length = 0;
	int threeCheck = 0;
	int nineCheck = 0;
	int zeroCheck = 0;
	int fiveCheck = 0;
	char potentialZero[2][10];
	char potentialFive[2][10];
	int k = 0;
	int x = 0;
	char hold;
	int sum = 0;
	int final = 0;
	for(int q = 0; q < 200; q++){
		for(int i = 0; i < 14; i++){
			if(i > 9){
				fscanf(fp, "%s", digits[i - 10]); //collect the output digits
			}else{
				fscanf(fp, "%s", wires[i]); //collect the input digits
			}
		}

		for(int i = 0; i < 10; i++){
			length = strlen(wires[i]);
			if(length == 2){ //1 is the only digit with length 2
				strcpy(decode[1], wires[i]);
			}if(length == 3){ //7 is the only digit with length 3
				strcpy(decode[7], wires[i]);
			}
			if(length == 4){//4 is the only digit with length 4
				strcpy(decode[4], wires[i]);
			}
			if(length == 7){//8 is the only digit with length 7
				strcpy(decode[8], wires[i]);
			}
		}
		for(int i = 0; i < 10; i++){
			length = strlen(wires[i]);
			
			if(length == 5){
				for(int j = 0; j < 5; j++){ //use 7 to find 3 since it's the only digit of length 5 that has all of 7's placements
					if(decode[7][0] == wires[i][j] || decode[7][1] == wires[i][j] || decode[7][2] == wires[i][j]){
						threeCheck++;
					}
				}
				if(threeCheck == 3){
					strcpy(decode[3], wires[i]);
				}
				threeCheck = 0;
			}
		}

		for(int i = 0; i < 10; i++){
			length = strlen(wires[i]);
			if(length == 6){
				for(int j = 0; j < 6; j++){ //use 3 to find 9 in the same way as finding 3
					if(decode[3][0] == wires[i][j] || decode[3][1] == wires[i][j] || decode[3][2] == wires[i][j] || decode[3][3] == wires[i][j] || decode[3][4] == wires[i][j]){
						nineCheck++;
					}
				}
				if(nineCheck == 5){
					strcpy(decode[9], wires[i]);
				}
				nineCheck = 0;
			}
		}

		for(int i = 0; i < 10; i++){
			length = strlen(wires[i]); //find the values that could be 0 or 6
			if(length == 6 && (strcmp(wires[i], decode[9]) != 0)){
				strcpy(potentialZero[k], wires[i]);
				k++;
			}
			if(length == 5 && (strcmp(wires[i], decode[3]) != 0)){
				strcpy(potentialFive[x], wires[i]);
				x++;
			}
		}

		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 6; j++){ //using 1 to find 0
				if(decode[1][0] == potentialZero[i][j] || decode[1][1] == potentialZero[i][j]){
					zeroCheck++;
				}
			}
			if(zeroCheck == 2){
				strcpy(decode[0], potentialZero[i]);
				if(i == 0){
					k = 1;
				}else{
					k = 0;
				}
				strcpy(decode[6], potentialZero[k]); //other value is 6
			}
			zeroCheck = 0;
		}

		for(int j = 0; j < 5; j++){ //using 6 to find 5
			if(decode[6][0] == potentialFive[0][j] || decode[6][1] == potentialFive[0][j] || decode[6][2] == potentialFive[0][j] || decode[6][3] == potentialFive[0][j] || decode[6][4] == potentialFive[0][j] || decode[6][5] == potentialFive[0][j]){
				fiveCheck++;
			}
		}

		if(fiveCheck == 5){
			strcpy(decode[5], potentialFive[0]); 
			strcpy(decode[2], potentialFive[1]); //other value is 2
		}else{
			strcpy(decode[5], potentialFive[1]);
			strcpy(decode[2], potentialFive[0]);
		}

		for(int i = 0; i < 10; i++){ //sort each wiring digit in alphabetical order
			length = strlen(decode[i]);
			for(int j = 0; j < length - 1; j++){
				for(int l = j + 1; l < length; l++){
					if(decode[i][j] > decode[i][l]){
						hold = decode[i][j];
						decode[i][j] = decode[i][l];
						decode[i][l] = hold;
					}
				}
			}
		}

		

		for(int i = 0; i < 4; i++){ //sort output digits in alphabetical order
			length = strlen(digits[i]);
			for(int m = 0; m < length - 1; m++){
				for(int j = m + 1; j < length; j++){
					if(digits[i][m] > digits[i][j]){
						hold = digits[i][m];
						digits[i][m] = digits[i][j];
						digits[i][j] = hold;
					}
				}
			}
		}
		for(int i = 0; i < 4; i++){
			for(int w = 0; w < 10; w++){
				if(strcmp(digits[i], decode[w]) == 0){ //find which digit the input is equal to
					if(i == 0){
						sum = sum + (w * 1000);
					}
					if(i == 1){
						
						sum = sum + (w * 100);
					}
					if(i == 2){
						sum = sum + (w * 10);
					}
					if(i == 3){
						sum = sum + w;
					}

				}
			}
		}
		final = final + sum;
	for(int i = 0; i < 4; i++){
		digits[i][0] = '\0';
	}
	for(int i = 0; i < 10; i++){
		decode[i][0] = '\0';
	}
		//reset values
		threeCheck = 0;
		nineCheck = 0;
		fiveCheck = 0;
		zeroCheck = 0;
		k = 0;
		x = 0;
		sum = 0;
	}
	
	printf("Sum: %d\n", final);
	exit(1);
}