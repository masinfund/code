
typedef int Rank ;

 // 列表节点类的定义 
template <typename T> struct ListNode {
	T data ; 
	ListNode<T> * pre ;
	ListNode<T> * succ ;


	ListNode() { } 
	ListNode(T e , ListNode<T> * p = NULL , ListNode<T> * s = NULL) :
	data(e) , pre(p) , succ(s) {}

	// interface 
	ListNode<T> * insertPre(T const &e) ;
	ListNode<T> * insertSucc(T const &e) ;
} ;





template <typename T> class List {
private :
	int _size ;
	ListNode<T> * head ;
	ListNode<T> * tail ;

protected:
	void init() ; //列表创建时的初始化 
	int clear() ; //清除所有节点,返回删除节点的作用1
	void copyNodes(ListNode<T> * , int ) ; 
	//复制列表中自位置p起的n项
	void merge(ListNode<T> * & , int , List<T> & , ListNode<T> * , int) ;
	// 有序列表区间归并 
    // 都是对从p开始连续的n个节点进行排序 
	void mergeSort(ListNode<T> * & , int ) ;
	void selectionSort(ListNode<T> * , int) ;
	void insertionSort(ListNode<T> * , int) ;

public :
	List() { intit() ;}
	List(List<T> const &L) ;
	List(List<T> const &L , Rank r, int n) ;
	List(ListNode<T> * p , int n) ;

	//destructor
	~List() ;

	// read-only interface 
	Rank rank(ListNode<T> *p) const ;
	Rank size() const {return _size ;} 
	bool empty() const {return _size <= 0 ;}
	T& operator[](Rank r) const ; // 支持循秩访问但效率差
	ListNode<T> * first() const {return head->succ ;}
	ListNode<T> * last() const {return tail->pre ;}
	//判断节点是否有效
	bool valid(ListNode<T> * p) {return p && (tail != p) && (head != p) ;}
	int disordered() const ; // 判断是否已排序

	ListNode<T> *find(T const &e , int  n , ListNode<T> *p ) const ;
	ListNode<T> * find(T const &e) const {
		return find(e,_size , tail) ;
	}
	ListNode<T> * search(T const &e , int n , ListNode<T> *p) const;
	ListNode<T> * search(T const & e) const {
		return search(e,_size , tail) ;
	}
	ListNode<T> *search(T const &e , int n , ListNode<T> *p) const ;


	ListNode<T> *selectMax(ListNode<T> *p , int n) ;
	ListNode<T> *selectMax() {return selectMax(head->succ , _size) ;}

	// write - acess interface 
	ListNode<T> *insertAsFirst(T const &e) ;
	ListNode<T> *insertAsLast(T const &e) ;
	ListNode<T> *insertBefore(ListNode<T> *p , T const &e) ;
	ListNode<T> *insertAfter(ListNode<T> *p , T const &e) ;
	
	T remove(ListNode<T> * p) ;
	
	void merge(List<T> &L) {merge(first(),size,L,L.first(),L._size) ;}
	void sort(ListNode<T> *p , int n) ;
	void sort() {sort(first() , _size) } ;

	int deduplicate() ;
	int uniquify() ;
	void reverse() ;

	void traverse(void(*) (T &)) ;
	template <typename VST> void traverse(VST &) ;
};
