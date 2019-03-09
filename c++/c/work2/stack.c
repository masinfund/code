#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void InitStack(LiStack *s)
{
	s->data = 0 ;
	s->next = NULL ;
}

void Push(LiStack *s , ElemType item)
{
	LiStack *tmp ;
	tmp = (LiStack *) malloc(sizeof(LiStack)) ;
	if(!tmp)
		return ;
	tmp->data = item ;
	tmp->next = s->next ;
	s->next = tmp ;
	s->data++ ;
	tmp = NULL ;
}

ElemType Pop(LiStack *s)
{
	if(!s)
		exit(EXIT_FAILURE) ;
	if(!s->next){
		printf("underflow") ;
		exit(EXIT_FAILURE) ;
	}
	LiStack *tmp  = s->next ;
	ElemType num = tmp->data ;
	s->next = tmp->next ;
	free(tmp) ;
	s->data-- ;

	return num ;
}

int Isempty(LiStack *s)
{
	if(!s)
		return 0 ;
	return s->next == NULL ;
}

void Destroy(LiStack *s)
{
	if(!s)
		return ;
	LiStack *tmp = s->next ;
	while(tmp){
		s->next = tmp->next ;
		free(tmp) ;
		if(!s->next)
			break ;
		tmp = s->next  ;
	}
	s->data = 0 ;
	tmp = s = NULL ;
}

ElemType *top(LiStack *s) 
{
	if(!s || !s->next)
		return NULL ;
	return &s->next->data ;
}


/*
void Makeempty(Sqstack *s) 
{
	if(!s){
		return ;
	}
	s->top = -1 ;
}

bool Isempty(const Sqstack *s )
{
	if(!s){
		return false ;
	}
	return (s->top == -1 ? true : false ) ;
}

bool Initstack(Sqstack *s) 
{
	if(!s){
		return false ;
	}
	s->top = -1 ;
	return true ;
}

void Push( Sqstack *s , int i) 
{
	if(s->top == STACK_SIZE - 1){
		printf("stack overflow\n") ;
		return ;
	}
	s->data[++s->top] = i ;

}

int Pop(Sqstack *s , int *elem) 
{
	if(s->top == -1){
		return -1;
	}
	*elem = s->data[s->top--] ;
	return 0 ;
}

void Show(const Sqstack *s)
{
	while(!Isempty(s)){
		int tmp ;
		printf("%c",tmp) ;
	}
	printf("\n") ;
	
}
int Gettop(const Sqstack *s)
{
	if(!s && !Isempty(s)){
		return 2147483647 ;
	}
	return s->data[s->top] ;
}

typedef struct _node {
	int data ;
	struct _node *next ;

} Node ;
static Node *top = NULL ;
static void terminate(const char *message)
{
	printf("%s\n",message) ;
	exit(EXIT_FAILURE) ;
}
void make_empty(void)
{
	while(!is_empty())
		pop() ;
}

bool is_empty(void)
{
	retrun top == NULL ;
}
bool is_full(void)
{
	return false ;
}

void push(int i )
{
	Node *new_node =(Node *) malloc(sizeof(Node)) ;
	if(new_node == NULL){
		terminate("error in push : stack is full.") ; 
	}

	new_node->data = i ;
	new_node->next = top ;
	top = new_node ;

	new_node = NULL ;
}

int pop(void)
{
	struct node *old_top ;
	int i ;
	if(is_empty()){
		terminate("Error in pop : stack is empty.") ;
	}
	old_top = top ;
	i = top->data ;
	top = top->next ;
	free(old_top) ;
	old_top = NULL ;

	return i ;

}*/