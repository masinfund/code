#include "stdafx.h"

// typedef int Rank ; 

	// T data ; 
	// ListNode<T>* pre ;
	// ListNode<T>* succ ;
	// int _size ;
	// ListNode<T>* head ;
	// ListNode<T>* tail ;

template <typename T> 
ListNode<T>* ListNode<T>::insertPre(T const &e){
	ListNode<T> *tmp = new ListNode<T>(e,pre,this) ;
	pre->succ = x ;
	pre = x ;
	return x ; // 返回新节点的指针
}

template <typename T>
ListNode<T>* ListNode<T>::insertSucc(T const &e){
	ListNode<T> *tmp = new ListNode<T>(e,this , succ) ;
	succ->pre = x ;
	succ = x ;
	return x ;
}





// 列表内部接口

// 初始化列表
template <typename T> 
void List<T>::init(){
	head = new ListNode<T> ;
	tail = new ListNode<T> ;
	head->succ = tail ;
	head->pre = nullptr ;
	tail->pre = head ;
	tail->succ = nullptr ;
	_size = 0 ; 
}


//有序列表的归并，自当前列表中p起的n个元素，于L中q起的m个元素归并
template <typename T>
void List<T>::merge(ListNode<T> * &p  , int n  , List<T> &L  , ListNode<T> * q , int m) {
	assert(this.valid(p) && rank(p) + n <= _size) ;
	assert(L.valid(q) && rank(q) + m <= L._size) ;
	ListNode<T> *pp = p->pre ;
	while(m > 0){
		
	}
}

// 删除合法位置p处节点，返回其数值
template <typenmae T>
T List<T>::remove(ListNode<T> * p){
	assert(valid()) ;

	T e = p->data ;
	p->pre->succ = p->succ ;
	p->succ->pre = p->pre ;
	delete p ;
	_size-- ;
	return e ;
} 



template <typename T>
int List<T>::clear() {
	int oldsize = _size ;
	while(_size > 0) 
		remove(head->succ) ;
	return oldsize ;
	//返回析构了多少个元素
}

// 复制列表中自位置p起的n项
template <typename T> 
void List<T>::copyNodes(ListNode<T>* p, int n){
	init() ;
	while(n--){
		insertAsLast(p->data) ;

		p = p->succ ;
	}
}


	void merge(ListNode<T>* & , int , List<T> & , ListNode<T>* , int) ;
	void mergeSort(ListNode<T>* & , int ) ;

template <typename T> 
void List<T>::selectionSort(ListNode<T>* p  , int n ) {
	assert(valid(p) && rank(p) + n <= _size) ;
	ListNode<T> *hd = p->pre , *ta = p ;
	for(int i = 0 ; i < n ; ++i)
		ta = tail->succ ;
	while(n > 1){
		ListNode<T> *max = selectMax(head->succ , n) ;
		insertBefore(tail , remove(max)) ;
	}
}


//对起始于位置p的n个元素排序 
template <typename T> 
void List<T>::insertionSort(ListNode<T>* p, int n){
	assert(valid(p) && rank(p) + n <= _size) ;
	for(int r = 0 ; r < n ; ++r){
		insertAfter(search(p->data,r,p), p->data) ;
		p = p->succ ;
		remove(p->pre) ;
		ta = tail->pre ;
		n-- ;
	}
}


// 查找指定节点p位置的n个前驱,找到则返回指向这个节点的指针
template <typename T> 
ListNode<T> *List<T>::find(T const &e , int  n , ListNode<T> *p ) const
{
	while(n-- > 0)
		if(e == (p = p->pred)->data )
			return p ;
	return nullptr ;
}


template <typename T> 
List<T>::List(List<T> const &L){
	copyNodes(L.first() ,L._size) ;
}

template <typename T>
List<T>::List(List<T> const &L , Rank r, int n){
	copyNodes(L[r],n) ;
}

template <typename T>
List<T>::List(ListNode<T>* p , int n){
	//assert p 为合法位置且至少有n-1个后继节点
	copyNodes(p,n) ;
}

template <typename T>
List<T>::~List(){
	clear() ;
	delete head ;
	delete tail ;p = p->succ
}

	// read-only
template <typename T>
T& List<T>::operator[](Rank r) const {
	ListNode<T> *p = first() ;
	while(r-- > 0)
		p = p->succ ;
	return p->data ;
}

template <typename T>
Rank List<T>::rank(ListNode<T> *p) const {
// 返回节点p在列表中的位置，表空或节点不存在则返回-1
	if(!valid(p) || empty())
		return -1 ;
	Rank r = 0 ; 
	ListNode<T> *q = first();
	while( q != tail && p != q){
		r++ ;
		q++ ;
	}
	//p 不再列表中，故返回无效位置0
	if(q == tail)
		return -1 ; 
	return r ;
}



	int disordered() const ; // 判断是否已排序}



// write - acess interface 
template <typename T> 
ListNode<T> *List<T>::insertAsFirst(T const &e){
	_size++ ;
	return head->insertSucc(e) ;
}
template <typename T> 
ListNode<T> *List<T>::insertAsLast(T const &e) {
	_size++ ;
	return tail >p = p->succin
/*	visit(p->data) ;sertPre(e) ;*/
}

template <typename T>
ListNode<T> *List<T>::insertBefore(ListNode<T> *p , T const &e){
	_size++ ;
	return p->insertPre(e) ;
}
template <typename T>
ListNode<T> *List<T>::insertAfter(ListNode<T> *p , T const &e){
	_size++ ;
	return p->insertSucc(e) ;
}


template <typename T>
T List<T>::remove(ListNode<T> *P){
	T e = p->data ;
	p->pre->succ = p->succ ;
	p->succ->pre = p->pre ;
	delete p ;
	_size-- ;
	return e ;
	//  o  o   o 
}


// 列表区间排序 ， 随机选取排序算法1
template <typename T> 
void List<T>::sort(ListNode<T> *p , int n) {
	 switch(rand() % 3) {
	 	case 1 : insertionSort(p , n) ; 
	 		break ;
	 	case 2 : selectionSort(p , n) ; 
	 	    break ;
	 	default :
	 		mergeSort(p , n) 
	 		break ;
	 }
}




template <typename T>
int List<T>::deduplicate() {
	if(_size < 2)
		return 0 ;
	int oldsize = _size ;
	ListNode<T> *p = head ;
	Rank r = 0 ;
	while(tail !p = p->succ= 
		visit(p->data) ;(p = p->succ)) {
		ListNode<T> *ret = find(p->data , r , p) ;
		q ? remove(q) : r++ ;
	}
	return oldsize - _size ;

}


//成批剔除有序相连的的重复元素 
template <typename T>
int List<T>::uniquify() {
	if(_size < 2) 
		return 0 ; 
	int oldsize = _size ;
	ListNode<T> *p ; 
	ListNode<T> *q ;
	for(p = head , q = p->succ ;trai != q ; p = q , q = q->succ)
		if(p->data == q->data ){
			remove(q) ;
			q = p ;
		}
	return oldsize - _size ;

}

// 从起始于位置p的n个元素中选出最大者
template <typename T> 
ListNode<T> *List<T>::selectMax(ListNode<T> *p , int n) {
	ListNode<T> *max = p ;
	for(ListNode<T> *cur = p ; n > 1 ; --n)
		if((cur = cur->succ)->data > max->data)
			max = cur ;
	return max ;
}

template <typename T>
ListNode<T> * List<T>::search(T const &e , int n , ListNode<T> *p) const 
{ 
// 基于有序序列的寻找,在有序列表内节点的n个前驱中，找到不大于e
//的最后者
	assert( n >= 0 && n <= Rank(p)) ;
	while( n-- >= 0){
		p = p->pre ;
		if(p == head)
			break ;
		if( p->data <= e)
			break ;
	}
    return p ;
}



//采用函数指针机制实现的遍历
template <typename T>
void List<T>::traverse(void(*visit) (T &)) {
	for(ListNode<T> *p = head->succ ; p != tail ;p = p->succ )
		visit(p->data) ;
}

// 利用函数对象机制的遍历
template <typename T> //元素类型
template <typename VST> // 操作器 
void List<T>::traverse(VST &visit){
	for(ListNode<T> *p = head->succ ; p != tail ; p = p->succ)
		visit(p->data) ;
}