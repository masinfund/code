#ifndef _VECTOR_H_
#define _VECTOR_H_


typedef int Rank ;
#define DEFAULT_CAPACITY 50

template <typename T >
class Vector {
protected :
	Rank _size ;
	size_t _capacity ;
	T *_elem ; // 数据区
	void copyFrom(T const *A , Rank low ,Rank hi) ;
	void expand() ; // 空间不足时扩容
	/*
	分摊运行时间(amortized running time) : 按照某种假定的概率分布，对各种情况下
	所需执行时间的加权平均，故亦称作为期望运行时间(expected running time)

	*/

	void shrink() ; // 装填因子过小时压缩
	//装填因子(load factor) = _size / _capacity
	bool bubble(Rank low , Rank hi) ;
	void bbbleSort(Rank low , Rank hi) ;
	Rank max(Rank low , Rank hi) ;
	void selectionSort(Rank low , Rank hi) ;
	void merge(Rank low , Rank mid , Rank hi) ; //归并算法
	void mergeSort(Rank low , Rank hi) ;
	Rank partition(Rank low , Rank hi) ; // 轴点构造算法
	void quickSort(Rank low , Rank hi) ;
	void heapSort(Rank low , Rank hi) ;
public :
	
	//constructor 
	Vector(int c = DEFAULT_CAPACITY , int s = 0 , T v = 0) ;
	Vector(T const *A, Rank low , Rank  hi) ;
	Vector(T const *A , Rank n) ;
	Vector(Vector<T> const &V , Rank low , Rank hi) ;
	Vector(Vector<T> const &V) ;

	//destructor 
	~Vector() { delete []_elem ;}

	// read-only interface 
	Rank size() const {return _size ;} 
	bool empty() const {return !_size ;} 
	int disordered() const ;
	Rank find(T const &e) const {return find(e,0,_size) ;}
	Rank find(T const &e, Rank low , Rank hi) const ; // 无序向量区间查找
	Rank search(T const &e) const {return (_size <= 0) ? -1 : search(e,0,_size) ;}
	Rank search(T const &e, Rank low , Rank hi) const ;

	static Rank BinSearch(T * A  , T const &e , Rank lo , Rank hi);
	

	//write interface
	T& operator[](Rank r) const ;
	Vector<T> &operator=(Vector<T> const &) ;
	T remove(Rank r) ; // 删除秩为r的元素
	int remove(Rank low , Rank hi) ; // 删除秩区间[low,hi)内的元素
	Rank insert(Rank r,T const &e) ;
	Rank insert(T const &e) {return insert(_size,e) ;}
	void sort(Rank low , Rank hi) ;
	void sort() {sort(0,_size) ;} 
	void unsort(Rank low , Rank hi) ;
	void unsort() {unsort(0,_size) ;}
	int deduplicate() ; //无序去重
	int uniquify() ; // 有序去重	

	//visit 
	void traverse(void (*)(T &)) ; // 使用函数指针
	//使用函数对象，可全局性修改
	template<typename VST> void traverse(VST &) ;

} ; //Ve






//BinNode 

#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lch))


#define sibling(p) (\
	IsLChild(*(p)) ? \
	(p)->parent->rch :\
	(p)->parent->lch  \
) // 兄弟

#define uncle(x) (\
	IsLChild(*(x)->parent) ? \
	(x)->parent-parent->rch : \
	(x)->parent->parent->lch   \
)

#define FromParent(x) ( \
	IsRoot(x) ? _root : (\
	IsLChild(x) ? (x).parent->lch : (x).parent->rch \)
	\)
// 来自父亲的指针


#define statue(p) ((p) ? (p)->height : -1) 
typedef enum { red , black } RBColor ;

template <typename T> struct BinNode{
	
	T data ;
	BinNode<T> * parent ;
	BinNode<T> *lch , *rch ;
	int height ;
	int npl ; // NULL Path Length 左式堆
	RBColor color ; // 红黑树 

	//constructor

	BinNode() : parent(NULL ) , lch(NULL) , rch(NULL) , 
				height(0) , npl(1) , color(red) { }
	BinNode( T e , BinNode<T> *p = NULL , BinNode<T> *lc = NULL ,
	 		BinNode<T> *rc = NULL , int h = 0 , int l = 1 , 
	 		RBColor c = red) : 
			data(e) , parent(p) , lch(lc) , rch(rc) ,
			height(h) , npl(l) , color(c) { }	


	int size() ;
	BinNode<T> *insertAsLc(T const &) ;
	BinNode<T> *insertAsRc(T const &) ;
	BinNode<T> *succ() ;   // 取当前节点的直接后继
	template <typename VST> void travLevel(VST &) ; // 层序遍历
	template <typename VST> void travPre(VST &) ; 
	template <typename VST> void travIn(VST &) ;
	template <typename VST> void travPost(VST &) ;

	// 比较器 ， 判等器

	bool operator<(BinNode const &bn) {return data < bin.data ;}
	bool operator==(BinNode const &bn) {return data == bn.data ;}

};



template <typename T> class BinTree{
protected:
	int _size ;
	BinNode<T> *_root ;
	virtual int updateHeight(BinNode<T> *x) ; 
	void updateHeightAbove(BinNode<T> *x)  ; // 更新节点x及其祖先的高度
public :
	BinTree() : _size(0) , _root(NULL) { }
	~BinTree() { if (_size > 0) remove _root ;}

	int size() const {return _size ;}
	bool empty() const { return !_root ;}
	BinNode<T> *root() const {return _root ;}
	BinNode<T> *insertAsRoot( T const &e) ;
	BinNode<T> *insertAsLc(BinNode<T> *x , T const &e) ; 
	// 作为左孩子插入，(原先无)
	BinNode<T> *insertAsRc(BinNode<T> *x , T const &e) ;
	BinNode<T> *attachAsLc(BinNode<T> *x , BinTree<T> *&t);
	// t作为x左子树接上
	BinNode<T> *attachAsRc(BinNode<T> *x , BinTree<T> *&t) ;
	int remove(BinNode<T> *x) ; 
	// 删除以位置x处节点为根的子树 ，返回该子树原先的规模
	BinTree<T> *secede(BinNode<T> *x) ;
	// 将x从当前树中摘除

	// 操作器
	template <typename VST> 
	void travLevel(VST &visit) { if(_root) _root->travLevel(visit) ;}
	template <typename VST>
	void travPre(VST &visit) { if (_root )}

} ;













#endif 