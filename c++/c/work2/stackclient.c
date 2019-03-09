#include <stdio.h>
#include "stackADT.h"
/*
stack create(void) ;
void destroy(Stack s) ;
void make_empty(Stack s ) ;
bool is_empty(Stack s) ;
bool is_full(Stack s) ;
int pop(Stack s) ;
void push(Stack s, int i ) ;
*/
int main(void)
{
	Stack s1,s2 ;
	int n ;

	s1 = create() ;
	s2 = create() ;
	push(s1,1) ;
	push(s2,2) ;

	n = pop(s1) ;
	printf("popped %d from s1\n",n) ;
	push(s2,n) ;
	n = pop(s1) ;
	print("popped %d from s1\n",n) ;
	push(s2,n) ;

	destroy(s1) ;

	while(!is_empty(s2))
		printf("Popped %d from s2\n",pop(s2)) ;

	push(s2,3) ;
	make_empty(s2) ;
	if(is_empty(s2))
		printf("s2 is empyt \n") ;
	else 
		printf("s2 is not empty") ;

	destroy(s2) ;

	return 0 ;
}