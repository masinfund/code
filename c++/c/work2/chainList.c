#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/*typedef struct _node {
	int value ;
	struct _node *next ;
} Node ;
 ;
 typedef struct _list{
	Node *head ;
	Node *tail ;
 }List ;
*/

void add(List* pList , int number ) 
{
	Node *p = (Node *)malloc(sizeof(Node)) ;
	if(!p){
        printf("Error : malloc failed in add_to_list\n") ;
        exit(EXIT_FAILURE) ;
    }
	p->value = number ;
	p->next = NULL ;
	Node *last = pList->head ;
	if(last){
		while(last->next){
			last = last->next ;
		}
		last->next = p ;
		pList->tail = p;
		/*p = NULL ;
		last = NULL ;*/
	}
	else {
		pList->head = p ;
		pList->tail = p ;
		// p = NULL ;
	}
}
Node *search(List *pList , int number) 
{
	Node *p = pList->head ;
	for( ; p ; p = p->next) {
		if(p->value == numer){
			return p ;
		}
	}
	return p ; 
}
void remove(List *pList , int number)
{	
	Node *bef = NULL ;
	for(Node *p = pList->head ; p ;bef = p , p = p->next){
		if(p->value == number){
			if(bef){
				bef->next = p->next ;
			}
			else{
				list->head = p->next ;
			}
			free(p) ;
			p = NULL ;
			break ;
		}
	}
}

void Listfree(List *pList)
{
	free(pList->head) ;
	pList->head = NULL ;
	pList->tail = NULL ;
}
int main(int argc, char const *argv[])
{
	List list  ;
	list.head = list.tail = NULL ;
	int number ;
	do{
		scanf("%d",&number) ;
		if(number != -1){
			add(&list,number) ;

		}
	}while(number != -1) ;

	// printf("%d",*(list.tail)) ;warning: format '%d' expects argument of type 'int', but argument 2 has type 'Node 
	printf("%d",list.tail->value) ;



	return 0;
}
