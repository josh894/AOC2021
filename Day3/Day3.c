#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main (int argc, char *argv[]){
	char binary[1000][20];
	int track[12];
	int i = 0;
	int check = 0;
	char reduce[12];
	int equal = 0;
	int iteration = 0;
	int hold = 0;

	FILE *fp = fopen("Day3Input.txt", "r");
	if(fp == NULL){
		exit(1);
	}
	for(i = 0; i < 12; i++){
		track[i] = 0;
	}

	i = 0;
	while(fscanf(fp, "%s", binary[i]) != EOF){ //for each binary in input
		for(int j = 0; j < 12; j++){
			if(binary[i][j] == '0'){	
				track[j]--; //below 0 means 0 is more common in position
			}
			if(binary[i][j] == '1'){
				track[j]++; //above 0 means 1 is more common in position
			}
		}
		i++; //# of input
	}

	check = 0;
	for(int l = 0; l < 12; l++){ //for each position
		for(int m = 0; m < i; m++){ //for each binary string
			if(l == 0){ //first run
				if(binary[m][l] == '0'){	
					check--;
				}if(binary[m][l] == '1'){
					check++;
				}
			}else{
				//thins out strings that do not match the most common place values
				for(int z = 0; z < l; z++){
					if(binary[m][z] == reduce[z]){ //must match previous most common digits to be computed
						equal++;		
					}
				}
				if(equal == l){
					if(binary[m][l] == '0'){	
						check--;
					}if(binary[m][l] == '1'){
						check++;
					}
					iteration++;
					if(iteration == 1){
						hold = m;
					}
				}	
			}
			equal = 0;
		}

		if(check >= 0){ //if position was most 1s
			reduce[l] = '1';
		}else{ //if position was most 0s
			reduce[l] = '0';
		}
		if(iteration == 1){
			printf("%s\n", binary[hold]);	//prints string that matches all most common place values
		}
		check = 0;
		iteration = 0;
	}


//same as above, but computes least common placement
	check = 0;
	for(int l = 0; l < 12; l++){
		for(int m = 0; m < i; m++){
			if(l == 0){
				if(binary[m][l] == '0'){	
					check--;
				}if(binary[m][l] == '1'){
					check++;
				}
			}else{
				for(int z = 0; z < l; z++){
					if(binary[m][z] == reduce[z]){
						equal++;
					}
				}
				if(equal == l){
					if(binary[m][l] == '0'){	
						check--;
					}if(binary[m][l] == '1'){
						check++;
					}
					iteration++;
					if(iteration == 1){
						hold = m;
					}
				}	
			}
			equal = 0;
		}

		if(check >= 0){
			reduce[l] = '0';
		}else{
			reduce[l] = '1';
		}
		if(iteration == 1){
			printf("%s\n", binary[hold]); //prints string that matches all least common place values
		}
		check = 0;
		iteration = 0;
	}
	/*
	for(int k = 0; k < 12; k++){
		if(reduce[k] == '1'){
			exp1 = 11 - k;
			eps = eps + pow(2,exp1);
		}
	}
	
	
	for(int k = 0; k < 12; k++){
		if(track[k] < 0){
			exp1 = 11 - k;
			eps = eps + pow(2,exp1);
			printf("eps: %d, %d\n", k, eps);
		}
	}
	
	final = gamma * eps;
	printf("%d\n", final);
	*/
}