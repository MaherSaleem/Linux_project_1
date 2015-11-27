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
#include <ctype.h>//for isdigit function
/*
 *
 */
void start_interpreter(){

	//TODO say welcome to my program
	Stack s = init_stack();
	char input [30] ;
	printf("\n>  ");
	scanf("%s" , input);
	printf("\n");
	while(strcmp(input , "x") != 0){//while the input in not "x"(exit)

		//not valid input
		int type_of_input = check_input(input);
		if(type_of_input == NOT_VALID_INPUT){
			printf("undefined command\n");
			goto end;


		}
		//if the input is integer
		else if(type_of_input == INTEGER)
			doIntCommand(s , input );

		//if the type is operatiom (+ , & , | , ^ ) , we just push it to the stack
		else if(type_of_input == OPERATION)
			push(s , input , OPERATION);


		else if (type_of_input == CHAR)
		{
			//if user enter p , we print the contenet of stack
			if(input[0] == 'p')
				doPComand(s);
			if(input[0] == 'd')
				push(s , "d" , CHAR);//add this char to stack
			if(input[0] == 's')
				push(s , "s" , CHAR);//add this char to stack
			if(input[0] == 'e')
				doECommand(s );
		}



		end:
		printf("\n>  ");
		scanf("%s" , input);
		printf("\n");

	}
}

/*
 *
 */
int check_input(char * s){
	//to check if its allowed char command
//	printf("%d" , strlen(s));
	if(strlen(s) == 1)
	{
		if(s[0] == 's' || s[0] == 'e' || s[0] == 'p' || s[0] == 'd' || s[0] == 'x')
			return CHAR;

		else if(s[0] == '+' || s[0] == '&' || s[0] == '|' || s[0] == '^')
			return OPERATION;


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


/*
 *
 */
void doIntCommand(Stack s , char * input){
	push(s ,input , INTEGER);
}


/*
 *
 */
void doPComand(Stack s){
	printStack(s);
}

/*
 *
 */
void doDCommand(Stack s){
	if(isEmpty(s)){
		printf("the stack is empty! you cant delete top of it\n");
		return;
	}
	else{
		pop(s);
	}

}

/*
 *
 */
void doECommand(Stack s){
	NodePtr p = getTop(s);
	if(p->type == OPERATION){
		calaulate(s  , p->data[0] );//send the opeartion to calculate it
	}
	else if(p->type == CHAR){
		pop(s);//remove this letter
		if(p->data[0] == 'd')
			doDCommand(s);
		else if(p->data[0] == 's')
			doSCommad(s);
	}
}

void doSCommad(Stack s){
	if(s->next != NULL && s->next->next != NULL)//check if there is two nodes to swap them
	{
		NodePtr temp1 = pop(s);
		NodePtr temp2 = pop(s);
		push(s , temp1->data , temp1->type);
		push(s , temp2->data , temp2->type);


	}
	else{
		printf("there is less than two element , you can't do swap !!\n");
		push(s , "s" , CHAR);//the s returned to stack , it can be removed manully using d
	}
}

void calaulate(Stack s , char type){//type referce to operation type
	pop(s);//remove the operation

	char buffer[20];//to store the number in it
	//check if there is two nodes and that they are integers
	if(s->next != NULL && s->next->type == INTEGER
		&& s->next->next != NULL && s->next->next->type == INTEGER){
			
		if(type == '+')
			sprintf(buffer , "%d" ,atoi(pop(s)->data) + atoi(pop(s)->data));//convert the answer to string
		else if(type == '|')
			sprintf(buffer , "%d" ,atoi(pop(s)->data) | atoi(pop(s)->data));
		else if(type == '&')
			sprintf(buffer , "%d" ,atoi(pop(s)->data) & atoi(pop(s)->data));
		else if(type == '^')
			sprintf(buffer , "%d" ,atoi(pop(s)->data) ^ atoi(pop(s)->data));
		else
			printf("error\n");
			
		//push the result in the stack
		push(s , buffer , INTEGER);


;
	}
	else {
		printf("there is an error with this operation \n");
		buffer[0] = type;
		buffer[1] = '\0';
		push(s ,buffer , OPERATION );//return the op the the top of the stack
	}

}
