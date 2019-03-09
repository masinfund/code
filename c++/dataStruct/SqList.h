#pragma once
#ifndef _SEQUENCELIST_H
#define INIT_SIZE 200
#define LISTINCREASE 50

typedef int Elemtype;
//sequence list 
typedef struct _sqlist {
	Elemtype *elem = NULL ;
	int length = 0 ;
	int listsize = 0 ;
}SqList;

bool InitList(SqList *p);
bool DestroyList(SqList *p);
bool ClearList(SqList *p);
bool ListEmpty(const SqList *p);
int ListLength(const SqList *p);
int GetElem(const SqList *p, int idx);
int PriorElem(const SqList *p, Elemtype value);
int LocateElem(const SqList *p, Elemtype value);
bool ListDelete(SqList *p, int idx);
bool ListInsert(SqList *p, int idx, Elemtype  value);
int NextElem(const SqList *p,Elemtype  value); 
void ListInflate(SqList *p, int moresize);
void InsertSort(SqList *p);
void Union_order(SqList *lhs, SqList *rhs, SqList *newlist);
void Union_disorder(SqList *lhs, SqList *rhs , SqList *newlist);
void ListCopy(const SqList *p , SqList *to_p);
void Listshow(const SqList *p);
void Dele_repeat(SqList * p);
#endif 
