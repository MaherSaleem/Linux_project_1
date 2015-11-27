/*
 * Stack.c
 *
 *  Created on: Nov 26, 2015
 *      Author: Maher
 */

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

NodePtr  newNode(char * data , int type )
{
	NodePtr new  = (NodePtr)malloc(sizeof(Node));
	strcpy(new->data , data);
	new->type = type;
	new->next = NULL;
	return new;
}

Stack init_stack(){
	Stack s = newNode("" , 0);//dummy header
	return s;
}

int isEmpty(Stack s){
	return s->next == NULL;
}

Stack pop(Stack s){
	if(isEmpty(s))//TODO think about another thing
		return NULL;
	NodePtr popedElement = s->next;
	s->next = popedElement->next;
	return popedElement;

}

void push(Stack s ,char * data , int type  ){
	NodePtr new = newNode(data , type);
	new->next = s->next;
	s->next = new;
}

void printStack(Stack s){
	if(s->next != NULL){
		printf("%s\n" , s->next->data);
		printStack(s->next);
	}

}


