#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
	char begin[100];
	char bye[100];
	char end[100];
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int grid[1000][1000];
	int total = 0;

	
	FILE *fp = fopen("Day5Input.txt", "r");
	if(fp == NULL){
		exit(1);
	}

	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++){
			grid[i][j] = 0; //create 1000x1000 grid
		}
	}

	while(fscanf(fp, "%s %s %s", begin, bye, end) != EOF){ //process input
		char * token = strtok(begin, ","); //x1
		char * token2 = strtok(NULL, ","); //y1
		
		x1 = atoi(token);
		y1 = atoi(token2);
		printf("%d %d\n", x1, y1);

		char * token3 = strtok(end, ","); //x2
		char * token4 = strtok(NULL, ","); //y2
		x2 = atoi(token3);
		y2 = atoi(token4);

		if(x1 == x2){ //vertical line
			if(y1 > y2){
				for(int i = y2; i <= y1; i++){ //travel across it towards y1
					grid[x1][i]++; //increment one line going over point for each
				}
			}
			if(y1 < y2){ 
				for(int i = y1; i <= y2; i++){ //travel across it towards y2
					grid[x1][i]++;
				}
			}
		}else if(y1 == y2){ //vertical line
			if(x1 > x2){
				for(int i = x2; i <= x1; i++){ //travel across to x1
					grid[i][y1]++;
				}
			}
			if(x1 < x2){
				for(int i = x1; i <= x2; i++){//travel across to x2
					grid[i][y1]++;
				}
			}
		}else{
			if(x2 > x1 && y2 > y1){ //diagonal line '/' going right to 999,999
				int p = 0;
				for(int i = x1; i <= x2; i++){ 
					grid[i][y1+p]++;
					p++;
				}
			}
			if(x2 < x1 && y2 < y1){ //diagonal line '/' going left to 0,0
				int p = 0;
				for(int i = x1; i >= x2; i--){
					grid[i][y1-p]++;
					p++;
				}
			}
			if(x2 > x1 && y2 < y1){  //diagonal line '\' going right to 999,0
				int p = 0;
				for(int i = x1; i <= x2; i++){
					grid[i][y1-p]++;
					p++;
				}
			}
			if(x2 < x1 && y2 > y1){ //diagonal line '\' going left to 0,999
				int p = 0;
				for(int i = x1; i >= x2; i--){
					grid[i][y1+p]++;
					p++;
				}
			}
		}
	}
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++){
			if(grid[i][j] > 1){ //if point was crossed more than once
				total++;
			}
		}
	}

	printf("%d\n", total);
	fclose(fp);
}