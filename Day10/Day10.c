#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//if an error is found, calculate the score of the error
int errorCheck(char check){
	if(check == ')'){
		return 3;
	}else if(check == ']'){
		return 57;
	}else if(check == '}'){
		return 1197;
	}else if(check == '>'){
		return 25137;
	}

	return 0;
}

int main (int argc, char *argv[]){
	char input[105];
	char expect[105];
	int sum = 0;
	int x = 0;

	FILE *fp = fopen("Day10Input.txt", "r");
	if(fp == NULL){
		exit(1);
	}

	while(fscanf(fp, "%s", input) != EOF){
		int length = strlen(input);

		if(input[length - 1] != '{' || input[length - 1] != '(' || input[length - 1] != '<' || input[length - 1] != '['){ //part 1
			for(int i = 0; i < length; i++){
				if(input[i] == '{' || input[i] == '(' || input[i] == '<' || input[i] == '['){
					expect[x] = input[i]; //the expected value to close next
					x++;
				}else if(input[i] == '}'){
					if(expect[x - 1] == '{'){
						x--;
					}else{
						sum += errorCheck(input[i]);
						break;
					}
				}else if(input[i] == ')'){
					if(expect[x - 1] == '('){
						x--;
					}else{
						sum += errorCheck(input[i]);
						break;
					}
				}else if(input[i] == '>'){
					if(expect[x - 1] == '<'){
						x--;
					}else{
						sum += errorCheck(input[i]);
						break;
					}
				}else if(input[i] == ']'){
					if(expect[x - 1] == '['){
						x--;
					}else{
						sum += errorCheck(input[i]);
						break;
					}
				}
			}
			x = 0;
		}
	}
	printf("%d\n", sum);
	fclose(fp);
}