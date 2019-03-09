#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE 100 

struct stack_type{
	int contents[STACK_SIZE] ;
	int top ;
} ;

static void terminate(const char *message) 
{
	printf("%s\n",message) ;	
	exit(EXIT_FAILURE) ;
}

Stack create(void)
{
	Stack s = (struct stack_type * )malloc(sizeof(struct stack_type)) ;
	if(!s){
		terminate("Error in create : stack could not be create.") ;
	}
	s->top = 0;
	return s;
}
void destroy(Stack s){
	free(s) ;
}
void make_empty(Stack s)
{
	s->top = 0 ;
}
bool is_empty(Stack s) 
{
	return s->top == 0 ;
}

bool is_full (Stack s)
{
	return s->top == STACK_SIZE ;
}

void push(Stack s ,int i)
{
	if(is_full(s))
		terminate("Error in push : stack is full.") ;
	s->contents[s->top++] = i ;
}

int pos(Stack s)
{
	if(is_empty(s))
		terminate("Error in pop : stack is empty.") ;
	retrun s->contens[--s->top] ;	
}

// used linked-list implement 

struct node {
	int data ;
	struct node *next ;

} ;
struct stack_type{
	struct node *top ;
};

static void terminate(const *message)
{
	printf("%s\n",message) ;
	exit(EXIT_FAILURE) ;
}

Stack create(void)
{
	Stack s = (struct stack_type *)malloc(sizeof(struct stack_type)) ;
	if(!s)
	terminate("Error in create : stack could not be created.") ;
	s->top = NULL ;
	return s ;	
}

void destroy(Stack s )
{
	make_empty(s) ;
	free(s) ;
}
void make_empty(Stack s)
{
	while(!is_empty(s)) 
		pop(s) ;
}
bool is_empty(Stack s )
{
	return s->top == NULL ;
}
bool is_full(Stack s)
{
	return false ;
}

void push(Stack s , int i)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node)) ;
	if(new_node == NULL)
		terminate("Error in push : stack is full.") ;

	new_node->data = i ;
	new_node->next = s->top ;
	s->top = new_node ;

}
int pop (Stack s )
{
	struct node *old_top ;
	int i ;
	
	if(is_empty(s))
		terminate("Error in pop : stack is empty.") ;
	
	old_top = s->top ;
	i = old_top->data ;
	s->top = old_top->next ;
	
	free(old_top) ;
	old_top = NULL ;

	return i ;
}