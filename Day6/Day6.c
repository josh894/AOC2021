#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
	FILE *fp = fopen("Day6Input.txt", "r");
	if(fp == NULL){
		exit(1);
	}
	int length = 0;
	char input[1000];
	unsigned long zero = 0;
	unsigned long one = 0;
	unsigned long two = 0;
	unsigned long three = 0;
	unsigned long four = 0;
	unsigned long five = 0;
	unsigned long six = 0;
	unsigned long seven = 0;
	unsigned long eight = 0;
	unsigned long sum = 0;
	unsigned long hold = 0;

	fscanf(fp, "%s", input); 
	length = strlen(input);
	for(int i = 0; i < length; i++){
		if(input[i] == '1'){ //all fish with 1 day left
			one++;
		}if(input[i] == '2'){
			two++;
		}if(input[i] == '3'){
			three++;
		}if(input[i] == '4'){
			four++;
		}if(input[i] == '5'){
			five++;
		}
	}

	printf("Ones: %ld Twos: %ld Threes: %ld Fours: %ld Fives: %ld\n", one,two,three,four,five);
	sum = one + two + three + four + five;
	printf("Sum: %ld\n", sum);

	for(int i = 0; i < 256; i++){
		hold = zero; //fish duplicating are sent to hold
		zero = one;
		one = two;
		two = three;
		three = four;
		four = five;
		five  = six;
		six = seven + hold; //reset duplicating fish
		seven = eight;
		eight = hold; //duplicated fish
	}

	sum = one + two + three + four + five + six + seven + eight + zero; //sum that
	printf("Sum: %ld\n", sum); //boom done

	/*
	int iter = 0;
	int workingIter = 0;
	int j = 0;
	for(int i = 0; i < length; i++){
		if(input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3'){
			fish[iter] = input[i] - '0';
			iter++;
		}
		if(input[i] == '4' || input[i] == '5' || input[i] == '6' || input[i] == '7'){
			fish[iter] = input[i] - '0';
			iter++;
		}
	}
	for(int i = 0; i < 256; i++){
		workingIter = iter;
		for(j = 0; j <= workingIter; j++){
			if(fish[j] == 0 && j != workingIter){
				fish[j] = 6;
				iter++;
				fish[iter] = 8;
			}else{
				fish[j]--;
			}
		} 
		printf("%d: %d\n", i, iter);
	}
	printf("End: %d Where: %d\n", iter, fish[iter]);
	*/


	exit(1);
}