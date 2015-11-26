/*
 ============================================================================
 Name        : Linux_pro1.c
 Author      : Maher Saleem
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
int main() {


	Stack s = init_stack();
	push(s ,"1130" ,INTEGER );
	push (s , "c" , CHAR);


	printStack(s);

	printf("%s\n" , pop(s)->data);
	printf("%s\n" , pop(s)->data);


	return EXIT_SUCCESS;
}
