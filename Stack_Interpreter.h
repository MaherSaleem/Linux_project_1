/*
 * Stack_Interpreter.h
 *
 *  Created on: Nov 26, 2015
 *      Author: Maher
 */

#ifndef STACK_INTERPRETER_H_
#define STACK_INTERPRETER_H_


#define  NOT_VALID_INPUT -1

/*
 *
 */
void start_interpreter();

/*
 * this function checks if the command entered by the user is vllid
 * it return the type of it if its valid
 * -1 if its not valid
 */
int check_input(char * s);

/*
 * this function is used when the user enter an integer
 * it push this integer to the stack
 */
void doIntCommand(Stack s , char * input);

/*
 * this function is used when the user enterd p
 * it print the content of the stack
 */
void doPComand(Stack s);

/*
 *
 */
void doDCommand(Stack s);
#endif /* STACK_INTERPRETER_H_ */
