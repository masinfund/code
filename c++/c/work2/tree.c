#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


BiTree *Create() {
	BiTree *t = (BiTree *)malloc(sizeof(BiTree));
	if (!t) {
		fprintf(stderr, "malloc wrong");
		return NULL;
	}
	t->data = 0;
	t->lch = NULL;
	t->rch = NULL;

	return t;
}

void Add(BiTree *t, ElemType e )
{
	// add follow DLR order 
	if (!t) {
		t = Create();
		t->data = e;
		return;
	}
	if(!t->lch){
		Add(t->lch) ;
	}
	else if(!t->rh){
		Add(t->rch) ;
	}
	

}

void Preorder(BiTree *t, void(*visit)(BiNode *e)) {
	if (t) {
		visit(t);
		Preorder(t->lch, visit);
		Preorder(t->rch, visit);
	}
}

void visit_print(BiNode *e) {

	printf("%d  ", e->data );
}
