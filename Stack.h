/*
 * Stack.h
 *
 *  Created on: Nov 26, 2015
 *      Author: Maher
 */

#ifndef STACK_H_
#define STACK_H_


//define the type in the stack , INTEGER or CHAR
#define  INTEGER 1
#define CHAR 2
#define OPERATION 3

typedef struct node Node;
typedef Node* Stack;
typedef Node* NodePtr;

/*
 * struct for nodes in stack
 * signle linked list is used
 */

typedef struct node{
	char  data [30];
	int type;
	Node * next;
};

/*
 * this function create new node for the stack
 * and return pointer to this node
 */
NodePtr  newNode(char * data , int type );



/*
 * this function is used to create the stack
 * it create a dummy node  , and return pointer to it
 */
Stack init_stack();


/*
 * this funtion is used to remove the top of the stack
 * and return pointer to it
 */
Stack pop(Stack s);


/*
 * this funtion is used to add new element to the stack
 */
void push(Stack s ,char * data , int type  );

/*
 * boolean function check if the stack is empty
 */
int isEmpty(Stack s);

/*
 * function to print stack recursively
 */
void printStack(Stack s);


/*
 * this function return a pointer to the top of stack
 * without removing it from stack
 */
NodePtr getTop(Stack s);
#endif /* STACK_H_ */
