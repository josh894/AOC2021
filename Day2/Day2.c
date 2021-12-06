#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]){
	int length = 0;	
	char direction[20];
	int hori = 0;
	int vert = 0;
	int total = 0;
	int aim = 0 ;

	FILE *fp = fopen("Day2Input.txt", "r");
	if(fp == NULL){
		exit(1);
	}

	while(fscanf(fp, "%s %d", direction, &length) != EOF){
		printf("%d\n", length);
		if(strcmp(direction, "forward") == 0){ //if sub moves forward
			hori = hori + length; //increase horizontal length
			vert = vert + (length * aim); //increase vertical movement by degree of angle
			printf("%s\n", direction);
		}
		if(strcmp(direction, "down") == 0){
			aim = aim + length; //down increases aim since going deeper into water
		}
		if(strcmp(direction, "up") == 0){
			aim = aim - length;
		}
	}

	total = hori * vert;
	printf("%d\n", total);
}