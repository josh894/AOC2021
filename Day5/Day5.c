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
			grid[i][j] = 0;
		}
	}

	while(fscanf(fp, "%s %s %s", begin, bye, end) != EOF){
		char * token = strtok(begin, ",");
		char * token2 = strtok(NULL, ",");
		
		x1 = atoi(token);
		y1 = atoi(token2);
		printf("%d %d\n", x1, y1);

		char * token3 = strtok(end, ",");
		char * token4 = strtok(NULL, ",");
		x2 = atoi(token3);
		y2 = atoi(token4);

		if(x1 == x2){
			if(y1 > y2){
				for(int i = y2; i <= y1; i++){
					grid[x1][i]++;
				}
			}
			if(y1 < y2){
				for(int i = y1; i <= y2; i++){
					grid[x1][i]++;
				}
			}
		}else if(y1 == y2){
			if(x1 > x2){
				for(int i = x2; i <= x1; i++){
					grid[i][y1]++;
				}
			}
			if(x1 < x2){
				for(int i = x1; i <= x2; i++){
					grid[i][y1]++;
				}
			}
		}else{
			if(x2 > x1 && y2 > y1){
				int p = 0;
				for(int i = x1; i <= x2; i++){
					grid[i][y1+p]++;
					p++;
				}
			}
			if(x2 < x1 && y2 < y1){
				int p = 0;
				for(int i = x1; i >= x2; i--){
					grid[i][y1-p]++;
					p++;
				}
			}
			if(x2 > x1 && y2 < y1){
				int p = 0;
				for(int i = x1; i <= x2; i++){
					grid[i][y1-p]++;
					p++;
				}
			}
			if(x2 < x1 && y2 > y1){
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
			if(grid[i][j] > 1){
				total++;
			}
		}
	}

	printf("%d\n", total);
	fclose(fp);
}