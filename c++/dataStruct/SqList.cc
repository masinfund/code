#include "stdafx.h"
/*

*/

bool InitList(SqList *p)
{
	p->elem = (Elemtype * )malloc(sizeof(Elemtype) * INIT_SIZE);
	if (!p->elem) {
		return false;
	}
	p->length = 0;
	p->listsize = INIT_SIZE;
	return true;
}
bool DestroyList(SqList *p)
{
	if (!p->elem ) {
		return  false;
	}
	free(p->elem);
	p->listsize = 0;
	p->length = 0;
	p->elem = NULL;
	return true;
}
bool ClearList(SqList *p)
{
	if (!p->elem) {
		return false; //  if p points to NULL , SqList doesn't  exists.
	}
	int idx = p->length;
	for (int i = 0; i != idx ; ++i) {
		p->elem[i] = 0;
		p->length--; 
	}
	p = NULL;
	return true;

}
bool ListEmpty(const SqList *p)
{
	if (!p->elem) {
		exit(EXIT_FAILURE);
	}
	if (!p->length){
		return true;
	}
	return false;
}

int ListLength(const SqList *p)
{
	if (!p->elem) {
		return -1;
	}
	return p->length;
}
int GetElem(const SqList *p, int idx)
{
	if (!p->elem) {
		return -1;
	}
	if(idx >= 0 && idx < p->length )
		return p->elem[idx];
}

int LocateElem(const SqList *p, Elemtype value)
{
	if (!p->elem) {
		return -1;
	}
	for (int i = 0; i != p->length; ++i) {
		if (value == p->elem[i]) {
			return i;
		}
	}
	return -1;
}

int PriorElem(const SqList *p, Elemtype value )
{
	int idx = LocateElem(p, value);
	if (idx == 0 ) {
		printf("in subscript %d position no predecessor\n", idx);
		return -1;
	}
	return p->elem[idx - 1];
}

int NextElem(const SqList *p, Elemtype value)
{
	int idx = LocateElem(p, value);
	if (idx == p->length - 1) {
		printf("in subscript %d position no successor \n", idx);
		return -1;
	}
	return p->elem[idx + 1];
}

bool ListInsert(SqList *p, int idx, Elemtype value)
{
	// inserting value before subscript idx .
	if (!p->elem) {
		exit(EXIT_FAILURE);
	}
	if (p->length >= p->listsize) {
		ListInflate(p, LISTINCREASE);
	}
	if (idx >= 0 && idx <= p->length - 1) {
		for (int i = p->length - 1 ; i != idx - 1; --i) {
			p->elem[ i + 1] = p->elem[i];
		}
	}
	else {
		return false;	
	}
	p->elem[idx] = value;
	p->length += 1;
	p = NULL;
	return true;
}
bool ListDelete(SqList *p, int idx)
{
	if (!p->elem) {
		exit(EXIT_FAILURE);
	}
	if (idx >= 0 && idx <= p->length - 1) {
		for (int i = idx + 1; i != p->length; ++i) {
			p->elem[i - 1] = p->elem[i];
		}
	}
	else {
		return false;
	}
	p->length -= 1;
	p = NULL;
	return true;
}

void ListInflate(SqList *p, int moresize)
{
	if (!p->elem) {
		exit(EXIT_FAILURE);
	}
	Elemtype* a = NULL ;
	a = (Elemtype *)malloc(sizeof(Elemtype) * (moresize + p->listsize));
	if (!a) {
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i != p->length; ++i) {
		a[i] = p->elem[i] ;
	}

	free(p->elem);
	p->elem = a;
	p->listsize += moresize;
	a = NULL;
}
void InsertSort(SqList *p)
{
	if (!p->elem) {
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i != p->length ; ++i) {
		int j = i - 1;
		int tmp = p->elem[i];
		while (tmp < p->elem[j] && j >= 0) {
			p->elem[j + 1] = p->elem[j];
			j--;
		}
		p->elem[j + 1] = tmp ;
	}
}

void  ListCopy(const SqList *p , SqList *to_p)
{
	if (!p->elem) {
		exit(EXIT_FAILURE);
	}
	if(to_p->elem){
		free(to_p->elem);
		to_p->length = 0;
		to_p->listsize = 0;
	}
	to_p->elem = (Elemtype *)malloc(sizeof(Elemtype) * p->listsize);
	if (!to_p->elem) {
		exit(EXIT_FAILURE);
	}
	to_p->listsize = p->listsize ;
	for (int i = 0; i != p->length ; ++i) {
		to_p->elem[i] = p->elem[i];
		to_p->length += 1;
	}


}
void Dele_repeat(SqList * p)
{
	if (!p->elem) {
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < p->length - 1; ++i) {
		for (int j = i + 1 ; j < p->length; ++j) {
			if (p->elem[j] == p->elem[i]) {
				ListDelete(p, j);
				//a mistake , p->length has subtracted one , so j-- ; 
				--j;
			}
		}
	}
}
void Union_disorder( SqList *lhs, SqList *rhs , SqList *newlist)
{
	
	if (!lhs->elem && !rhs->elem)
		exit(EXIT_FAILURE);
	Dele_repeat(lhs);
	Dele_repeat(rhs);
	if (!newlist->elem) {
		ListCopy(rhs,newlist);
	}
	else {
		DestroyList(newlist);
		ListCopy(rhs, newlist);
	}

	int idx = newlist->length;
	for (int i = 0; i != lhs->length; ++i) {
		if (idx >= newlist->listsize) {
			ListInflate(newlist, LISTINCREASE);
		}
		newlist->elem[idx++] = lhs->elem[i];
	}

	Dele_repeat(newlist);
}
void Union_order( SqList *lhs, SqList *rhs , SqList *newlist)
{ 
	if (!lhs->elem || !rhs->elem) {
		exit(EXIT_FAILURE);
	}
	if (newlist->elem) {
		ClearList(newlist);
	}
	else {
		InitList(newlist);
	}
	InsertSort(lhs);
	InsertSort(rhs);

	int idx = (lhs->length > rhs->length) ? rhs->length : lhs->length;
	Elemtype min = lhs->elem[0];
	Elemtype max = rhs->elem[0];
	for (int i = 0 ; i != idx; ){
		if (i >= newlist->listsize || newlist->length >= newlist->listsize ) {
			ListInflate(newlist, LISTINCREASE);
		}
		if ( min > max ) { //  
			newlist->elem[i] = max;
			newlist->length++;
			max = rhs->elem[++i];
		}
		else{
			newlist->elem[i] = min;
			newlist->length++;
			min = max;
			max = lhs->elem[++i ];
		}
	}
	int i = idx;
	if (i >= newlist->listsize) {
		ListInflate(newlist, LISTINCREASE);
	}
	while (i < rhs->length) {
		if (newlist->length >= newlist->listsize) {
			ListInflate(newlist, LISTINCREASE);
		}
		newlist->elem[i] = rhs->elem[i++];
		newlist->length++;
	}
	while (i < lhs->length) {
		if (newlist->length >= newlist->listsize) {
			ListInflate(newlist, LISTINCREASE);
		}
		newlist->elem[i] = lhs->elem[i++];
		newlist->length++;
	}
	Dele_repeat(newlist);
}

void Listshow(const SqList *p)
{	
	if (!p->elem) {
		printf("List  is empty");
		return;
	}
	printf("\n List length is %d , Listsize is %d \n", p->length, p->listsize);
	for (int i = 0; i != p->length; ++i) {
		printf("%3d   ", p->elem[i]);
		if ((i % 10 + 1) == 0)
			puts("");
	}
	puts("");
}

int main(void)
{
	/*
	bool InitList(SqList *p);
	bool DestroyList(SqList *p);
	bool ClearList(SqList *p);
	bool ListEmpty(const SqList *p);
	int ListLength(const SqList *p);
	int GetElem(const SqList *p, int idx);
	int PriorElem(const SqList *p, int value);
	int LocateElem(const SqList *p, int value);
	bool ListDelete(SqList *p, int idx);
	bool ListInsert(SqList *p, int idx, int value);
	int NextElem(const SqList *p, int value);
	void ListInflate(SqList *p , int moresize) ;
	void ListCopy(const SqList *p ) ;
	SqList *Union_order( SqList *lhs, SqList *rhs) ;
	SqList *Union_disorder(const SqList *lhs, const SqList *rhs) ;

	// list sort
	void InsertSort(SqList *p) ;
	void BubbleSort(SqList *p) ;
	*/


	SqList new_list,l1,l2;
	InitList(&l1);
	InitList(&l2);
	InitList(&new_list);
	puts("l2 is not iniialize  ");
	Listshow(&l2);
	srand((unsigned)time(NULL));
	for (int i = 0; i != new_list.listsize; ++i) {
		new_list.elem[i] = rand() / INIT_SIZE + 1;
		new_list.length++;
	}
	puts("new_list is inialized ");
	Listshow(&new_list);
	printf("listlength is %d\n", ListLength(&new_list) );
	printf("Getelem at %d  is %d\n", 0, GetElem(&new_list, 0));
	printf("Priorelem test . before %d is %d \n", GetElem(&new_list, 1), PriorElem(&new_list, GetElem(&new_list, 1)));
	ListInsert(&new_list,0, 7);
	puts("List insert test ");
	Listshow(&new_list);
	puts("List delete test");
	ListDelete(&new_list, 1);
	Listshow(&new_list);
	puts("List inflate test");
	ListInflate(&new_list, LISTINCREASE);
	Listshow(&new_list);
	for (int i = 0; i != l2.listsize; ++i) {
		l2.elem[i] = rand() / INIT_SIZE + 1;
		l2.length++;
	}
	puts("l2 is initialized");
	Listshow(&l2);
	Dele_repeat(&l2);
	puts("l2 is no repeat number ");
	Listshow(&l2);
	Union_disorder(&new_list,&l2,&l1);
	puts("l1 is not order");
	Listshow(&l1 );
	InsertSort(&l1);
	puts("sort list l1 ");
	Listshow(&l1);
	Union_order(&new_list, &l2, &l1);
	puts("order list l1 ");
	Listshow(&l1);
	puts("clear list new_list ");
	ClearList(&new_list);
	Listshow(&new_list);
	puts("destroy test");
	DestroyList(&new_list);
	DestroyList(&l2);
	DestroyList(&l1);
	puts("destroylist l2 ");
	Listshow(&l2);
	return 0 ;
}
