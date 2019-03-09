#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 100

struct node {
    int value ;
    struct node *next ;
} *first = NULL ;

/*
typedef struct _node{
		int value ;
		struct _node *next ;
	} Node ;
	Node *p ; 

	That's ok ;
*/
struct node *add_pto_list(struct node **list , int num);
struct node *search_list(struct node * list ,int n) ;
struct node *delete_from_list(struct node *list ,int n) ;



int main(void)
{	
	return 0 ;
	
}


struct node *add_pto_list(struct node **list , int num)
{
    struct node *new_node ;
    new_node = (struct node *)malloc(sizeof(struct node)) ;
    if(!new_node){
        printf("Error : malloc failed in add_to_list\n") ;
        exit(EXIT_FAILURE) ;
    }
    new_node->value = num ;
    new_node->next = *list ;
    *list = new_node ;
    return new_node ;

}

struct node *search_list(struct node *list, int n) 
{
	for ( ; list != NULL ; list = list->next )
		if ( list ->value == n )
			return list ;
	return NULL ;
}
struct node *delete_from_list(struct node *list ,int n)
{
	struct node *cur , *prev ;
	for(cur = list , prev = NULL ; cur != NULL && cur-> value != n ; prev = cur , cur = cur->next ){
		;
	}	
	if(!cur){
		printf("NOT FOUND ") ;
		return list ;
	}
	if(!prev){
		// cur value is n . break ; prev == NULL ;
		printf("%d is in the first node ",n) ;
		list = list->next ;
	}
	else 
		prev->next = cur->next ;
	
	free(cur) ;

	cur = NULL ;
	return list ;
}