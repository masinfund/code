#ifndef _NODE_H_
#define _NODE_H_

typedef struct _node {
	int value ;
	struct _node *next ;
} Node ;

typedef struct _list{
Node *head ;
Node *tail ;
}List ;


void add(List* pList , int number ) ;
Node *search(List *pList , int number) ;
void remove(List *pList , int number) ;
void Listfree(List *pList) ;

#endif 