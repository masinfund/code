#ifndef _QUEUE_H
#define _QUEUE_H 

#define MAXSIZE 100
typedef int Elem ;


typedef struct  {
	Elem base[MAXSIZE] ;
	int front ;
	int rear ;
}SeQueue ;

typedef struct _node{
	Elem data ;
	struct _node *pre ;
	struct _node *succ ; 
}Node ;

typedef struct {
	Node *head ;
	Node *tail ;
}LinkQueue ;

void InitSeQueue(SeQueue *q);
void ClearSeQueue(SeQueue *q);
bool IsEmpty(SeQueue v);
int Length(SeQueue v);
void GetHead(SeQueue v, Elem *elem);
void EnterSeQueue(SeQueue *q, Elem elem);
void DeleSeQueue(SeQueue *q, Elem *elem);
void Show(SeQueue v);


#endif 