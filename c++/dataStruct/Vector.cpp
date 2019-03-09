#include "Vector.h"

template <typename T >
void Vector<T>::copyFrom(T const *A , Rank low ,Rank hi) {
	_elem = new T[_capacity = 2 * (hi - low)] ;
	_size = 0 ;
	while(low < hi)
		_elem[_size++] = A[low++] ;
	//O(_size) ~ O(n)
}

template <typename T> 
void Vector<T>::expand() {
	if(_size < _capacity) 
		return ;
	if(_capacity < DEFAULT_CAPACITY) 
		_capacity = DEFAULT_CAPACITY ;
	T *old = _elem ;
	_elem = new T[_capacity <<= 1] ;
	for(int i = 0 ; i < _size ; ++i)
		_elem[i] = old[i] ;
	delete []old ;
} // 空间不足时扩容

template <typename T>
void Vector<T>::shrink(){
	if(_capacity < DEFAULT_CAPACITY)
		return ;
	if(_size << 3 > _capacity) // 剩余数据大于25%时不收缩
		return ;
	T *old = _elem ;
	_elem = new T[_capacity >>= 1] ;
	for(int i = 0 ; i < _size ;++i)
		_elem[i] = old[i] ;
	delete []old ;

} // 装填因子过小时压缩

template <typename T> 
bool Vector<T>::bubble(Rank low , Rank hi){
	bool sroted = true ;
	while(++low < hi) 
		if(_elem[low - 1] > _elem[low]) {
			sorted = false ;
			swap(_elem[low - 1] , _elem[low]) ;
		}
	return sorted ;
}

template <typename T >
void Vector<T>::bbbleSort(Rank low , Rank hi) {
	while(!bubble(low , hi--)) ;
}

template <typename T>
Rank Vector<T>::max(Rank low , Rank hi) {
	Rank max = low ;
	while(low++ < hi) {
		if(max < _elem[low])
			max = low ;
	}
	return max ;
}

template <typename T > 
void Vector<T>::mergeSort(Rank low , Rank hi){
	if(hi - low < 2 )
		return ;
	int mi = (low + hi) >> 1 ;
	merSort(low , mi) ;
	merSort(mi , hi) ;
	merge(low , mi , hi) ;
}


template <typename T> 
void Vector<T>::merge(Rank low , Rank mid , Rank hi) {
	T *A = _elem + low ;
	int lb = mid - low ; T *B = new T[lb] ;
	for(Rank i = 0 ; i < lb ; B[i] = A[i++]) ;
	int lc = hi - mi ; 
	T *C = _elem + mi ; 
	for(Rank i = 0  , j = 0 , k = 0 ; (j < lb ) || (k < lc) ; ) {
		if((j < lb) &&(!(k < lc) || (B[j] <= C[k])))
			A[i++] = B[j++] ;
		if((k < lc) && ((!j < lb) || (C[k] < B[j])))
			A[i++] = C[k++] ;
	}
	delete [] B ;
} //归并算法



void selectionSort(Rank low , Rank hi) ;
	Rank partition(Rank low , Rank hi) ; // 轴点构造算法
	void quickSort(Rank low , Rank hi) ;
	void heapSort(Rank low , Rank hi) ;

	
	//constructor 
template <typename T>
Vector<T>::Vector(int c = DEFAULT_CAPACITY , int s = 0 , T v = 0){
	_elem = new T[_capacity = c] ;
	for(_size = 0 ; _size < s ; _elem[_size++] = v)
		;
}
template <typename T>
Vector<T>::Vector(T const *A, Rank low , Rank  hi){
	copyFrom(A,low,hi) ;
}

template <typename T>
Vector<T>::Vector(T const *A , Rank n){

	copyFrom(A , 0 , n) ;
} // 整体复制 

template <typename T>
Vector<T>::Vector(Vector<T> const &V , Rank low , Rank hi){
	copyFrom(V._elem , low , hi) ;
}

template <typename T>
Vector<T>::Vector(Vector<T> const &V){
	copyFrom(V._elem , 0 , V._size) ;
}



// 返回向量中逆序相领元素对的总数
tempalte <typename T>
int Vector<T>::disordered() const {
	int cnt = 0 ; // counter 
	for(int i = 1 ; i < _size; ++i)
		if(_elem[i -1] > _elem[i])
			++n ;
	return n ;
} 

template <typename T>
Rank Vector<T>::find(T const &e, Rank low , Rank hi) const {
	assert(low >= 0 && hi <= _size) ;
	while((low < hi--) && (e != _elem[hi]))
		;
	return hi ; // 成功则返回最后一个等于e 的元素的位置 ，失败时返回-1 
}// 无序向量区间查找



template <typename T> 
Rank Vector<T>::search(T const &e, Rank low , Rank hi) const {
	while(low < hi ) {
		Rank mid = (low + hi) >> 1 ;
		(e < _elem[mi]) ? hi = mid : low = mid + 1 ;
	}
	return --low ;
}

	//write interface
template <typename T> 
T& Vector<T>::operator[](Rank r) const {
	return _elem[r] ;
}

template <typename T> 
Vector<T> &Vector<T>::operator=(Vector<T> const &V){
	if(_elem) 
		delete []_elem ;
	copyFrom(V.elem,0,V.size()) ;
	return *this ;
}

//[low,hi)
template <typename T>
int Vector<T>::remove(Rank low , Rank hi){
	if(low == hi)
		return 0 ;
	while(hi < _size)
		_elem[low++] = _elem[hi++] ;
	_size = low ;
	shrink() ;
	return hi - low ; // 返回被删除元素的数目
} // 删除秩区间[low,hi)内的元素

template <typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r] ;
	remove(r,r + 1) ;
	return e ;
} // 删除秩为r的元素

template <typename T>
Rank Vector<T>::insert(Rank r,T const &e){
	//e插入秩为r
	expand() ;
	for(int i = _size ; i > r ; --i)
		_elem[i] = _elem[i - 1];
	_elem[r] = e ;
	_size++ ;
	return r ;
}

template <typename T> 
void Vector<T>::sort(Rank low , Rank hi){
	switch(rand() % 5) {
		case 1 :
			bubbleSort(low , hi) ;
			break ;
		case 2 :
			selectionSort(low , hi) ;
			break ;
		case 3 :
			mergeSort(low ,hi) ;
			break ;
		case 4 : 
			heapSort(low ,hi) ;
			break ;
		default:
			quickSort(low , hi) ;
			break ;
	}
}

template <typename T> 
void Vector<T>::unsort(Rank low , Rank hi) {
	T *V = _elem + low ;
	for(Rank i = hi - low ; i > 0 ; --i)
		swap(V[i - 1] , V[rand() % i]) ; //swap #include <utility>
}

template <typename T> 
int Vector<T>::deduplicate(){
	int oldsize = _size ;
	for(Rank i = 1 ; i < _size ; ){
		(find(_elem[i],0,i) < 0 ) ? i++ : remove(i) ;
	}
	return oldsize - _size ;
	// 被删除元素总数
} //无序去重

template <typename T >
int Vector<T>::uniquify(){
	// int old_size = _sie ;
	// int i = 1 ;
	// while(i < _size)
	// 	_elem[i -1] == _elem[i] ? remove(i) : i++ ;
	// return old_size - _size ;
	Rank i = 0 , j = 0 ;
	while(++j < _size)
		if(_elem[i] != _elem[j])
			_elem[++i] = _elem[j] ;
	_size = ++i ;
	shrink() ;
	return j - i ;

} // 有序去重	


template <typename T> static 
Rank 

	//visit
template <typename T> 
void Vector<T>::traverse(void (*visit)(T &)) {
	for(int i = 0 ; i < _size ; ++i)
		vist(_elem[i]) ;
} // 使用函数指针

template <typename T>   //操作器
template<typename VST> void Vector<T>::traverse(VST &visit)
{
	for(int i = 0 ; i < _size ; ++i)
		visit(_elem[i]) ; // visit函数对象
}
							//使用函数对象，可全局性修改

template <typename T>
struct Increase {
	virtual void operator()(T &e) {e++ ;}
}

template <typename T> 
void increase(Vector<T> &v) {
	v.traverse(Increase<T> ()) ;
}





// BinNode 
template <typename T>
BinNode<T> *BinNode<T>::insertAsLc(T const &e) {
	return lch = new BinNode(e , this) ; 
}

template <typename T> 
BinNode<T> *BinNode<T>::insertAsRc(T const &e) {
	return rch = new BinNode(e , this) ;
}

template <typename T> 
template <typename VST> 
void BinNode<T>::travIn(VST & visit){
	switch(rand() % 5) {
		case 1 : travIn
	}
}


template <typenmae T> 
int BinTree<T>::updateHeight(BinNode<T> *x) 
{
	return x->height = 1 + max(statue(x->lch) , statue(x->rch)) ;
}

template <typename T> 
void BinTree<T>::updateHeightAbove(BinNode<T> *x) 
{
	while(x) {
		updateHeight(x) ; 
		x = x->parent ;
	}
}

template <typename T> 
BinNode<T> *BinTree<T>::insertAsRoot(T const &e) 
{
	_size = 1 ;
	return _root = new BinNode<T>(e) ; 
}

template <typename T> 
BinNode<T> *BinTree<T>::insertAsLc(BinNode<T> *x , T const &e)
{
	_size++ ;
	x->insertAsLc(e) ;
	updateHeightAbove(x) ;
	return x->lch ;
}

template <typename T> 
BinNode<T> BinTree<T>:: insertAsRc(BinNode<T> *x , T const &e)
{
	_size++ ;
	x->insertAsRc(e) ; 
	updateHeightAbove(x) ; 
	return x->rch ;
}

template <typename T> 
BinNode<T> BinTree<T>::attachAsLc(BinNode<T> *x , BinTree<T> * &s) 
{
	if(x->lch = s->_root)
		x->lch->parent = x ;
	_size += s->_size ; 
	updateHeightAbove(x) ;
	s->_root = NULL ;
	s->_size = 0 ; 
	release(s) ;
	s = NULL ;
	return x ;
}x->

template <typename T> 
BinNode<T> BinTree<T>::attachAsRc(BinNode<T> *x , BinTree<T> * &s) 
{
	if(x->rch = s->_root)
		x->rch->parent = x ;
	_size += s->_size ; 
	updateHeightAbove(x) ;
	s->_root = NULL ;
	s->_size = 0 ; 
	release(s) ;
	s = NULL ;
	return x ;
}


template <typename T> 
int BinTree<T>::remove(BinNode<T> *x) {
	FromParent(*x) = NULL ;
	updateHeightAbove(x->parent) ;
	int n = removeAt(x) ;
	_size -= n  ;
	return n ;
}

template <typename T> 
satic int removeAt(BinNode<T> *x) {
	if( !x)
		return 0 ;
	int n = 1 + removeAt(x->ch) + removeAt(x->rch) ;
	release(x->data) ;
	release(x) ;
	return n ;
}

template <typename T>
BinTree<T> *BinTree<T>::secede(BinNode<T> *x) {
	FromParent(*x) = NULL ;
	BinTree<T> *s = new BinTree<T> ;
	s->_root = x ;
	x->parent = NULL ;
	s->_size = x->size() ;
	_size -= s->_size ;
	return s ;
}