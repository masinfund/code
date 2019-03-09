#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
	算法流程 ： 假如文本串ss匹配到i , 模式串p匹配到j .
	if(j == -1 || ss[i] == p[j]) {i++ ,j++ ;}
	else if(j != -1 && ss[i] != p[j]) j = next[j] ;
	// 匹配失败时，模式串向右移动的位数 = 失配字符所在位置 - 
				失配字符对应的next[j] , 即 j - next[j] 

				移动位数 = 已匹配的字符数 - 对应的部分匹配值(pmt)    


	PMT(Partial Match Table)部分匹配表 : 其中是字符串的前缀集合和后缀集合
				交集中最长元素的长度。
	前缀 ： 对于字符串a , b  , IF a = bx , 其中x是任意的非空字符串， 那么
			b为a的前缀。
			ex :
		...
		ababab
		 {"a","ab","aba","abab","ababa"}
		 {"b","ab","bab","abab","babab"} 
		    pmt[5] = 4 ;
		abababc
		 {"a","ab","aba","abab","ababa","ababab"}
		 {"c","bc","abc","babc","ababc","bababc"}
		    pmt[6] = 0 ;
		abababca
		 {"a","ab","aba","abab","ababa","ababab","abababc"} ;
		 {"a","ca","bca","abca","babca","ababca","bababca"} ;
			pmt[7] = 1 ;
		...

	pmt[] = { 0 , 0 , 1 ,2 ,3 ,4 ,0 , 1}
	把pmt向右进行偏移，而故意的把0位至于-1 , 以便于编程。 
	next = {-1(0),0 , 0 ,1 ,2 ,3, 4 , 0}
		

*/


int stringMatch(const char *s , const char *t )
{
	char *ms = (char *)s , *ss = (char *)t ;
	int i = 0  ,j = 0 ;
	//'\0' 
	while(ms[i] && ss[j]){
		if(ms[i] == ss[j]){
			++i ;
			++j ;
		}
		else {
			//i 退 j 位 进 1 .
			i = i - j + 1 ;
			j = 0 ; 
		}
	}
	if(!ss[j]){
		return i - j ;
	}
	else 
		return -1 ;
}

void next(const char *ps , int *next , int len)
{
	next[0] = -1 ;
	int idx = -1 , i = 0 ;
	while(i < len){
		if(idx == -1 || ps[idx] == ps[i])
			next[++i] = ++idx ;
		else
			idx = next[idx] ;
	}
	for(int i = 0 ; i != len ; ++i)
		printf("%d  ",next[i]) ;
	 puts("") ;
}

int kmp(const char *ss , const char *p)
{
	int *n = (int *)malloc(strlen(p) * sizeof(int)) ;
	next(p , n , strlen(p)) ;
	int i = 0  , j = 0 ; 
	// j = -1 时 ， strlen 返回的是unsigned 会导致比较大小出错
	//while( i < (long )strlen(ss) && j < (long)strlen(p))
	int ssl = strlen(ss) , pl = strlen(p) ;
	while(i < ssl && j < pl){
		if( j == -1 || ss[i] == p[j]){
			++i ;
			++j ;
		}
		else 
			j = n[j] ;
	}

	free(n) ;
	n = NULL ;
	if(!p[j])
		return i - j ;
	else 
		return -1 ;

}
/*
abddabcdabd
    abcdabd   
   a
  a 
 a
abc
*/

int main(void)
{
	int idx  ;
	const char *s1 = "abcdabdabdsddfadddddabcd" , *s2 = "bcd" ;
	printf("%d  \n",strlen(s1)) ;
	printf("%d\n",stringMatch(s1 , s2)) ;
	printf("%d\n",idx = kmp(s1,s2));
	printf("%s\n",s1 + idx) ;
	return 0 ;
}