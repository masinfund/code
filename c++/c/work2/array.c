#include <stdio.h>
#include "array.h" 
#include <stdlib.h>

/*typedef struct _array {
	int *array ;
	int size ;
} Array ;
Array array_create(int init_size) ;
void array_free(Array *a) ;
int array_size(const Array *a) ;
int *array_at(Array *a , int index) ;
void array_inflate(Array *a , int more_size) ;
*/
int main(void)
{
	Array a = array_create(7) ;
	printf("%d\n",array_size(&a)) ;

	*array_at(&a,2) = 724 ;
	printf("%d\n",*array_at(&a,2)) ;
	
	array_inflate(&a,3) ;
	*array_at(&a,7) = 2 ;
	for(int i = 0 ; i != a.size ; ++i)
		printf("%d  ",a.array[i]) ;
	array_free(&a) ;

	return 0 ;

}
Array array_create(int init_size)
{
	Array a ;
	a.size = init_size ;
	a.array = (int * ) calloc(init_size, sizeof(int)) ;
	if(!a.array){
		perror("NO MEMMORY") ;
	}
	return a ;
}

void array_free(Array *a) 
{
	a->size = 0 ;
	free(a->array) ;
	a->array = NULL ;	
}

// 封装
int array_size(const Array *a) 
{
	return a->size ;	
}

int* array_at(Array *a , int index) 
{
	return &(a->array[index]) ;
}
void array_inflate(Array *a , int more_size) 
{
	int *p = (int *) calloc(a->size + more_size , sizeof(int)) ;
	for(int i = 0 ; i != a->size ; ++i){
		p[i] = a->array[i] ;
	}
	free(a->array) ;
	a->array = p ;
	p = NULL ;
	a->size += more_size ;
}
