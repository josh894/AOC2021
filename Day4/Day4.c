#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
	FILE *fp = fopen("Day4Input.txt", "r");
	if(fp == NULL){
		exit(1);
	}
	char input[1000];
	int picked[200];
	char * currnum;
	int i = 0;
	int board[5][5];
	int j = 0;
	int k = 0;
	int hold = 0;
	int sum = 0;
	int check = 0;
	int final = 0;
	int x = 0;
	int y = 0;
	int repeat = 0;
	int maxMoves = 0;
	int moves = 0;
	int boardNum = 0; //variable mess

	fscanf(fp, "%s", input); 
	while((currnum = strtok(i ? NULL : input, ",")) != NULL){
		picked[i] = atoi(currnum); //get each crab
		i++;
	}
	while(fscanf(fp, "%d", &hold) != EOF){
		board[x][y] = hold;
		//printf("%d ", board[x][y]);
		if(x == 4 && y == 4){
			boardNum++;
			for(int m = 0; m < i; m++){
				for(k = 0; k < 5; k++){
					for(j = 0; j < 5; j++){ 
						if( board[j][k] == picked[m]){ //if # on board matches called #
							board[j][k] = 999;
							moves++;
							for(int a = 0; a < 5; a++){
								for(int b = 0; b < 5; b++){
									if(board[a][b] == 999){ //check the board for a win
										check++;
									}
								}
								if(check == 5 && repeat == 0){ //if a win is found
									for(int c = 0; c < 5; c++){
										for(int d = 0; d < 5; d++){
											if(board[c][d] != 999){
												sum = sum + board[c][d]; //sum all unmarked #s
											}
										}
									}
									sum = sum * picked[m]; //multiply by last called #
									if(m > maxMoves){ //looking for the maximum moves to finish a board
										final = sum;
										maxMoves = m;
										printf("%d %d\n", boardNum, m);
									}
									sum = 0; //reset values
									repeat = 1;
									check = 0;
								}
								check = 0;
							}
							for(int b = 0; b < 5; b++){
								for(int a = 0; a < 5; a++){
									if(board[a][b] == 999){ //check the board for a win
										check++;
									}
								}
								if(check == 5 && repeat == 0){ //if a win is found
									for(int c = 0; c < 5; c++){
										for(int d = 0; d < 5; d++){
											if(board[c][d] != 999){
												sum = sum + board[c][d]; //sum all unmarked #s
											}
										}
									}
									sum = sum * picked[m]; //multiply by last called #
									if(m > maxMoves){ //looking for the maximum moves to finish a board
										final = sum;
										maxMoves = m;
										printf("%d %d\n", boardNum, m);
									}
									sum = 0; //reset values
									repeat = 1;
								}
								check = 0;
							}
						}
					}
				}
			}
			repeat = 0; //reset values
			sum = 0;
			check = 0;
			x = 0;
			y = 0;
		}else if(x == 4){
			x = 0;
			y++;
		}else{
			x++;
		}
		moves = 0;
	}
	k = 0;
	j = 0;
	printf("%d\n", final); //print final sum for longest move board
	exit(1);
}