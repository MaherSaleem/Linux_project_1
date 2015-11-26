/*
 * Stack_Interpreter.c
 *
 *  Created on: Nov 26, 2015
 *      Author: Maher
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"
#include "Stack_Interpreter.h"


void start_interpreter(){

	//TODO say welcome to my program
//	Stack s = init_stack();
	char input [30] ;
	printf(">");
	scanf("%s" , input);
//	int isValid = check_input(input);
	while(strcmp(input , "x") != 0){//while the input in not "x"(exit)
		if(check_input(input) == NOT_VALID_INPUT){
			printf("undefined command\n");
			goto end;
		}



		end:
		printf(">");
		scanf("%s" , input);
	}
}

//TODO
int check_input(char * s){
	//to check if its allowed char command
	if(strlen(s) == 1)
	{
		if(s[0] == 's' || s[0] == 'e' || s[0] == 'p' || s[0] == 'd' || s[0] == 'x')
			return CHAR;

		else if(isdigit(s[0]))
			return INTEGER;
		else
			return NOT_VALID_INPUT;
	}
	//the length is more than one
	else{
	//to check if its number
	int i;
	for(i = 0 ; i < strlen(s) ; i++)
		if(!isdigit(s[i]))//if its more than one letter , then all digits should be numbers
			return NOT_VALID_INPUT;
	return INTEGER;
	}

}
