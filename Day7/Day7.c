#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
	FILE *fp = fopen("Day7Input.txt", "r");
	if(fp == NULL){
		exit(1);
	}
	int crabs[2000];
	char input[5000];
	char * currnum;
	int i = 0;
	int max = 0;
	long int sum = 0;
	long int final = 999999999999999;
	int movement = 0;
	int diff = 0;
	
	fscanf(fp, "%s", input); 
	printf("%s\n", input);

	while((currnum = strtok(i ? NULL : input, ",")) != NULL){
		crabs[i] = atoi(currnum); //get each crab
		printf("%d\n", crabs[i]);
		i++;
	}

	for(int j = 0; j < i; j++){
		if(crabs[j] > max){
			max = crabs[j];
		}
	}

	for(int j = 0; j < max; j++){
		for(int k = 0; k < i; k++){
			if(j > crabs[k]){ //if position is greater than where crab is
				//sum = sum + j - crabs[k];
				for(int p = crabs[k]; p <= j; p++){ //increment fuel usage for each move towards j
					sum = sum + diff;
					diff++;
				}
			}else if(crabs[k] > j){ //if position is less than where crab is
				//sum = sum + crabs[k] - j;
				for(int p = j; p <= crabs[k]; p++){ //same increment method
					sum = sum + diff;
					diff++;
				}
			}
			diff = 0;
		}
		if(sum < final){
			final = sum;
		}
		sum = 0;
	}
	printf("%ld\n", final);
	exit(1);
}