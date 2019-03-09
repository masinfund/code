#ifndef _STDCK_H
#define _STDCK_H
#define STACK_SIZE 100
#include <stdbool.h>

typedef int ElemType  ;
typedef struct Node {
	ElemType data ;
	struct Node *next ;
}LiStack ;

void InitStack(LiStack *s) ;
int Isempty(LiStack *s) ;
void Destroy(LiStack *s) ;
ElemType Pop(LiStack *s) ;
void Push(LiStack *s , ElemType item) ;
ElemType *top(LiStack *s) ;
#endif 
