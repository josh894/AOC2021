#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int BOUNDS[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1},}; //Shoutout to omae

int trackBasin = 0;
int index = 0;
int length = 0;

int findBasin(int x, int y, int basin[100][100], char input[100][100]){
	basin[x][y] = 1;
	int depth = 1;

	for(int k = 0; k < 4; k++){  //calculate bounds on which adjacent values can be checked
		int xBound = x + BOUNDS[k][0];
		int yBound = y + BOUNDS[k][1];
		if(xBound < 0 || yBound < 0 || xBound >= index || yBound >= length){
			continue; //skip this iteration
		}
		if((input[xBound][yBound] != '9') && (basin[xBound][yBound] == 0) && (input[xBound][yBound] > input[x][y])){
			depth += findBasin(xBound, yBound, basin, input); //add one to the basin value
		}
	}
	return depth;
}

int main (int argc, char *argv[]){
	char input[100][100];
	int basin[100][100];
	int sum = 0;
	int trackBound = 0;
	int trackSmall = 0;
	int depth = 0;
	int deepest[3] = {0,1,2};

	
	FILE *fp = fopen("Day9Input.txt", "r");
	if(fp == NULL){
		exit(1);
	}

	while(fscanf(fp, "%s", input[index]) != EOF){
		length = strlen(input[index]);
		index++;
	}

	for(int i = 0; i < index; i++){
		for(int j = 0; j < length; j++){
			basin[i][j] = 0; //set values to 0 for future checking
		}
	}


	for(int i = 0; i < index; i++){
		for(int j = 0; j < length; j++){
			trackBound = 0;
			trackSmall = 0;
			for(int k = 0; k < 4; k++){ //omae the goat for this fr
				int xBound = i + BOUNDS[k][0];
				int yBound = j + BOUNDS[k][1];
				if(xBound < 0 || yBound < 0 || xBound >= index || yBound >= length)
					continue;
				trackBound++;
				if(input[i][j] < input[xBound][yBound]){
					trackSmall++;
				}
			}
			if(trackBound == trackSmall){ //if the amount of adjacent values are less than the current
				sum += 1 + input[i][j] - '0'; //for sum of all lowest points
				depth = findBasin(i,j,basin,input);
					if(depth > deepest[0] && depth != deepest[1] && depth != deepest[2]){ //make sure the three values are different
						int hold = deepest[0];
						deepest[0] = depth;
						if(hold > deepest[1]){ //to prevent largest value from taking all three spots of array
							int holdH = deepest[1];
							deepest[1] = hold;
							if(holdH > deepest[2]){
								deepest[2] = holdH;
							}
						}else if(hold > deepest[2]){ //to prevent largest value from taking all three spots of array
							int holdS = deepest[2];
							deepest[2] = holdS;
							if(holdS > deepest[1]){
								deepest[2] = holdS;
							}
						}
					}
			}
		}
	}
	int deep = deepest[0] * deepest[1] * deepest[2];

	printf("%d %d\n",sum, deep);


	fclose(fp);
	exit(1);
}