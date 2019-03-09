#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

void Print( List L ); /* 细节在此不表 */

List Reverse( List L )
{
	if(L == NULL ){
		return NULL ;
	}
	if(!L->Next){
		return L ;
	}
	PtrToNode cur = L, seq = L->Next ;
	cur->Next = NULL ;
	while(seq){
		PtrToNode tmp = seq->Next ;
		seq->Next = cur ;
		cur = seq ;
		seq = tmp ;
	}
	L = cur ;
	cur = NULL ;
	return L ;
}