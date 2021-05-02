#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>
#include <math.h>
#include <sys/time.h>

#define MAX_LIMIT 150

int main(int argc, char *argv[]){
	
	char result[MAX_LIMIT];
	if (argc != 2){
		printf("Invalid number of arguments, correct use is:\n ./output value\n");
		//printf("%d", argc);
		return -1;
	}
	
	
	int value;
	value = atoi(argv[1]);
	
	if (value > 26){
		value = value % 26;
	}
	
	printf("Enter string to be crypted: ");
	fgets(result,MAX_LIMIT,stdin);
	for(int i = 0; i < MAX_LIMIT; i++){
		if ((result[i] > 64 && result[i] < 91) || (result[i] > 96 && result[i] < 123)){
			 if ((result[i] + value > 90 && result[i] < 91) || (result[i] + value > 122)){
			 	result[i] = result[i] + value;
			 	result[i] = result[i] - 26;
			 } else {
			 	result[i] = result[i] + value;
				}
		}
		
	}
	
	printf("The Result is: %s",result);
	printf("\n");
	
	return 1;
}
