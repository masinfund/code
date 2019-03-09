#include <stdio.h>
#include "queue.h"

// typedef struct  {
// 	Elem base[MAXSIZE] ;
// 	int front ;
// 	int rear ;
// }SeQueue ;
//assert(q) ;


void InitSeQueue(SeQueue *q)
{
	q->front = q->rear = 0 ;	
}

void ClearSeQueue(SeQueue *q)
{
	q->front = q->rear = 0 ;
}
bool IsEmpty(SeQueue *v){
	return v->rear == v->front ;
}
int Length(SeQueue *v)
{
	return (v->rear + MAXSIZE - v->front) % MAXSIZE ;
}
void GetHead(SeQueue *v, Elemtype *elem)
{	
	if(!IsEmpty(v))
		*elem = v->base[v->front] ; 
}
void EnterSeQueue(SeQueue *q, Elemtype elem)
{
	if((q->rear + 1) % MAXSIZE == q->front)
		return ;
	q->base[q->rear] = elem ;
	q->rear = (q->rear + 1) % MAXSIZE ;
}
void DeleSeQueue(SeQueue *q, Elemtype *elem)
{
	if(IsEmpty(q))
		return ;
	*elem = q->base[q->front] ;
	q->front = (q->front + 1) % MAXSIZE ;
}
void Show(SeQueue v)
{
	while(!IsEmpty(&v)){
		Elemtype tmp ;
		DeleSeQueue(&v , &tmp) ;
		printf("%d  ", tmp) ;
	}	
	printf("\n") ;
}




//deque 

