#ifndef _TREE_H_
#define _TREE_H_

static int cnt ;
typedef int ElemType;
typedef struct BiNode {
	ElemType data;
	struct BiNode *lch, *rch;
}BiTree;

BiTree *Create();
void Preorder(BiTree *t , void (*visit)(BiNode *e) );
void Add(BiTree *t, ElemType e);
void visit(BiNode *e);

#endif 