#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>
#include "queue.h"



#define LOCAL 
#define N 100
#define BLOCK_SIZE 35
#define NUL '\0'
#define DEBUG 1
#define NAME_LEN 42
#define PI 3.1415926
//int i 声明并定义，使编译器为i留出了空间。
// extern int i   声明变量i而不是定义它

void find_two_largest( int * , int n , int * , int *) ;
char *find_char(char const *source , char const *chars) ;
int del_substr(char *str , char *substr) ;
char * match( char *str , char *want) ;
double PrimeSum(int n) ;
void ReverseWrod(void) ;
bool PerfectNum(int number) ;
void quick(int (*p)[N] , int row , int high) ;

const int MOD = 100000;
//static int a[N] ;


char* concat(const char *s1, const char *s2)
{
    char *result ;
    result = (char *) malloc(sizeof(char ) * (strlen(s1) + strlen(s2) + 1)) ;
    if(!result){
        printf("Erro : malloc failed in malloc\n") ;
        exit(EXIT_FAILURE) ;
    }
        strcpy(result,s1) ;
        strcat(result,s2) ;     
    return result ;
}
typedef int Type ;

typedef struct _array{
    Type *array ;
    unsigned size ;
} Array ;

Array array_create(Type init_size)  
{
    Array a ;
    a.size = init_size ;
    a.array = (Type *)malloc(sizeof(Type) * init_size) ;
    return a ;
}
void array_free(Array *a)
{
    free(a->array) ;
    a->size = 0 ;
    a->array = NULL ;
}

int array_size(const Array *a) 
{
    return a->size ;
}

/*int *array_locate(const Array *a , int index)
{
    if(index >= a->size ){
        array_inflate(a,(index / BLOCK_SIZE  + 1) * BLOCK_SIZE - a->size) ;
    }
    return &(a->array)[index] ;
}
*/
void array_set(Array *a , int index , Type value)
{
    a->array[index] = value ;
}

void array_inflate(Array *a , int moresize)
{
    Type *p = (Type *)calloc(moresize + a->size , sizeof(Type)) ;
    if(!p){
        printf("Erro : malloc failed in malloc\n") ;
        exit(EXIT_FAILURE) ;
    }
    for(int i = 0 ; i != a->size ; ++i){
        p[i] = (a->array)[i] ;
    }
    free(a->array);
    a->array = p ;
    a->size += moresize  ;
    p = NULL ;

}
int D_value(int m[] , int n )
{ 
    //minimum defference value return a[i] - a[j] = min (i != j) 
    int min = m[n -1] , temp ;
    for(int i  = 1 ; i != N ; ++i){
        temp = m[i] - m[i - 1] ;
        if(temp < min)
            min = temp ;
    }
    return min ;
}

struct date{
    int month ;
    int year ;
    int day ;
} ;
bool isLeap(struct date d)
{
    if(d.year % 400 == 0)
        return true ;
    else if( d.year % 4 == 0 && d.year % 100 != 0){
        return true ;
    }
    else 
        return false ;
}
int numberOfDays(struct date d)
{
    if(d.month = 2){
        if(isLeap(d)){
            return 29 ;
        }
        else {
            return 28 ;
        }
    }
    switch(d.month){
        case 4 : case 6 : case 9 : case 11 : 
            return 30 ;      break ;
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : 
        case 12 :    
            return 31 ;      break ;
        default :
            return -1 ;
    }

}



void fun(char *p1 , char *p2)
{
    if(!p1 || !p2){
        return ;
    }
    while(*p1++)
        ;
    do
    {
        *p1 = *p2++ ;
    }while(*p2) ;
}

long my_atoi(const char *str  , int *len) 
{
    int flag = 1;
    int num = 0 ;
    *len = 0 ;
    while(*str == ' ' || *str == '\r' || *str == '\t'){
        str++ ;
    }
    if(*str == '-' ){
        flag = -1 ;
        str++ ;
    }
    
    while(*str >= '0' && *str <= '9'){
        num = num * 10 + *str - '0' ;
        (*len)++ ;
        str++;
        if( num < 0){
            num = 2147483647 ;
            break ;
        }
    }
    return num * flag ;

}
/*
        if (!len)
            ++p;
        else
            printf("%d ", ch);
*/

// int ListMerge()

bool is_prime(int n)
{
    if( n <= 1)
        return false ;
    for(int div = 2 ; div * div <= n ; ++div){
        if( n % div == 0){
            return false ;
        }
    }
    return true ;

}

void bubble_sort(int *a , int n)
{
    for(int i = 0 ; i != n - 1 ; ++i){
        int flag = 1 , j;
        if(!flag){
            break ;
        }
        for( j = 0  ; j != n - i ; ++j){
            if(a[j + 1] < a[j]){
                a[j + 1 ] = a[j + 1 ] + a[j] ;
                a[j] = a[j + 1 ] - a[j] ;
                a[j + 1 ] = a[j + 1 ] - a[j] ;
            }
        }
    }
}

void show(int *a , int n)
{
    if(!a){
        fprintf(stderr,"a is null") ;
    }

    for(int i = 0 ; i != n ; ++i){
        printf("%3d  " , a[i]) ;
        if((i % 7 ) + 1 ==  0){
            puts("") ;
        }
    }
    puts("") ;
}

double pi(void)
{
     long long  i = 1 , flag = -1 ;
    double sum = 0.0 , frac = 1.0 ;
    while(frac > 1e-10 || frac < -1e-10){
        sum += frac ;
        frac = flag * 1.0 /(2 * i++ + 1) ;
        flag *= -1 ;
    }
    sum *= 4.0 ;
    printf("\n%.11f\n",sum) ;

    return sum ;

}
char* stockSummary(const char** lstOfArt, int szlst, const char** categories, int szcat) {
  // your code
  
  char *tmp = (char *)malloc(sizeof(char) * 2 ) ;
  if(!tmp){
    exit(EXIT_FAILURE) ;
  }
  strcpy(tmp," ") ;
  if(!szlst || !szcat)
      return tmp ;
  free(tmp) ;

  tmp = (char *)malloc(sizeof(char) * 17 * szcat) ;
  if(!tmp){
    exit(EXIT_FAILURE) ;
  }
  
 /*     char* art[5] = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 890", "DRTY 600"};
        char* cd[2] = {"A", "B"};
        dotest(art, 5, cd, 2, "(A : 200) - (B : 1140)");*/

  char *ls , *rs ;
  int  sum[szcat][2] ;
  for(int *p = &sum[0][0] ; p != &sum[szcat - 1][1] ;++p){
    *p = 0 ;
  }
  for(int i = 0 ; i != szcat ;++i ){
    rs = (char *)categories[i] ;
 
    for(int j = 0 ; j != szlst ; ++j ){
        int tmp = 0 ;
        ls = (char *)lstOfArt[j] ;
        if(*ls == *rs){
            sum[i][1] = *ls ;
            //skip alpha and space 
            while(!(*ls >= '0' && *ls <= '9')){
                ++ls ;
            }
            while(*ls){
                tmp = *ls++ - '0' + tmp * 10 ;
            }
            sum[i][0] += tmp ;
        }

    }
  }
  char *p = tmp , ch[10] = {'\0'} ;

  // dotest(art, 5, cd, 2, "(A : 200) - (B : 1140)")
  for( int i = 0 ; i != szcat ; ++i){
    int j = 0 ;
    *p++ = '(' ;  
    *p++ = sum[i][1] ;
    *p++ = ' ' ;
    *p++ = ':' ;
    *p++ = ' ' ;
    while(sum[i][0]){
        ch[j++] = sum[i][0] % 10 + '0' ;
        sum[i][0] /= 10 ;
    }
    while(j--){
        *p++ = ch[j] ;
    }
    *p++ = ')' ;
    *p++ = ' ' ;
    *p++ = '-' ;
    *p++ = ' ' ;
    for (int i = 0; i < 10; ++i)
    {
        ch[i] = '\0' ;
        /* code */
    }
  }
  *(p - 3) = '\0' ;
  return tmp ; 
  
}




int decipher(int *a , int n)
{
    if(n == 7){
        FILE *fp ;
        int cnt = 0 , num = 0 ; 
        fp = fopen("out.dat","ab") ;
        if(!fp){
            printf("Can't open %s \n","out.dat") ;
            exit(EXIT_FAILURE) ;
        }
        for(int i = 0 ;i != n ; ++i){
            fprintf(fp,"%d ",a[i]) ;
            cnt++ ;
            if(cnt == INT_MAX){
                cnt = 0 ;
                num++ ;

            }
        }
        fprintf(fp,"\n\n\t%d\t%d\n\n",cnt,num) ;
        fclose(fp) ;
        fp = NULL ;
        return 0 ;
    }
    for(int i = 0; i != 10 ; ++i){
        if(n == 0 || n == 3){
            decipher(a,n + 1) ;
        }
        else if(n == 2){
                if(a[n - 1] != i && a[n + 1] != i){
                    a[n] = i ;
                    decipher(a,n + 1) ;
                }
        }
        else {
            if(a[n - 1] != i){
                a[n] = i ;
                decipher(a,n + 1) ;
            }
        }
    }
    return 1 ;
}

int find(int a[][N] , int dim , int tar)
{
    int (*p)[N] = &a[0] , i  ;
    for(i = 0 ;i != N - 1 ; ++i){
        if( (*p)[i] == tar){
            return 1 ;
        }
        if((*p)[i] < tar && (*p)[i + 1] > tar){ 
            break ;
        }
    }
    for(int j = 0 ; j != N ; ++j){
        if(a[i][j] == tar)
            return 1 ;
    }
    return 0 ;
}

void minnum(int *a , int n) 
{
    if(n > 9){
        return ; 
    }
    int num = a[0] * 10 ;
    while(num % 10 < n - 1 ){
        num += 1 ;
        if(num / 10 > a[num % 10]){
            num = a[num % 10] * 10 + num % 10 ;
        }
    }
    printf("%d\n",num / 10 ) ;
}



int quick_sort(int *a , int low , int high)
{
    int pivot ;
    if(low >= high)
        return 0 ;
    int lh = low , rh = high ;
    int elem = a[low] ;

    while(lh < rh){
        while(a[rh] >= elem && lh < rh)
            rh-- ;
        if(lh == rh)    break ;
        a[lh++] = a[rh] ;
        while(a[lh] <= elem && lh < rh)
            lh++ ;
        if(lh == rh )   break ;
        a[rh--] = a[lh] ;
    }
    a[lh] = elem ;
    pivot = lh ;


    quick_sort(a , low , pivot - 1) ;
    quick_sort(a , pivot + 1 , high) ;
    return 0 ;
}
#define String(x) # x 
#define Link(a,b) a ## b 
#define Write(String) printf(#String) 
#define Print(n) printf(#n " = %d\n",n) 
#define Mk_ID(n) a##n 

void foo()
{
    // 竖式中所使用的数字必须全部使用输入的数字
    int count = 0 ;
    char s[20] , buf[99] ;
    scanf("%s",s) ;
    for(int abc = 111 ; abc <= 999 ; ++abc){
        for(int de = 11 ; de <= 99 ; ++de){
            int x = abc * (de % 10) , y = abc * (de / 10) , z = abc *de ;
            sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z) ;
            int ok = 1 ;
            for(int i = 0 ; i < strlen(buf) ; i++)
                if(strchr(s,buf[i]) == NULL)
                    ok = 0 ;
            if(ok){
                printf("<%d>\n",++count) ;
                printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",
                        abc,de,x,y,z) ;
            }

        }
    }
    printf("The number of solutions = %d\n",count) ;
}
//s 1764   buf 111166661111776



int main(void)
{   
/*#ifdef LOCAL
    freopen("in.dat","r",stdin) ;
    freopen("out.dat","w",stdout) ;
#endif
*/

    printf("%s \nCompiled on %s at %s\n", __FILE__ ,__DATE__ ,__TIME__) ;
    srand((unsigned)time(NULL)) ;
    

    FILE *fin , *fout ;
    fin = fopen("in.dat","rb") ;
    fout = fopen("out.dat","wb") ;
    if(!fin){
        perror("file can't be opened") ;
        exit(EXIT_FAILURE) ;
    }

    int x[5][5] = {0} ;
    for(int i = 0 ; i < 5 ; ++i){
        for(int j = 0 ; j < 5 ; ++j)
            printf("%d\t",x[i][j]) ;
        puts("") ;
    }



   /* if(freopen("out.dat","wb",stdout) == NULL){
        printf("file can't be opened ") ;
        exit(EXIT_FAILURE) ;
    }



   /* fclose(fp) ;
    fp = freopen("out.dat","wb",stdout) ;
    if(!fp){
        exit(EXIT_FAILURE) ;
    }


    
    if((fp = fopen("out.dat","ab")) == NULL){
        fprintf(stderr,"open file failed ") ;
        exit(EXIT_FAILURE) ;
    }
   // fwrite(a,sizeof(int),N, fp) ;

    //print 5 , show 0500 0000 

    // fwrite(a,sizeof(a[0]),sizeof(a) / sizeof(a) , fp) ;
  const char* art[5] = {"ABAR 200", "CDXE 500", "BKWR 250", "BTSQ 8930", "DRTY 600"};
  const char* cd[2] = {"A", "B"};
  char *p = NULL ;
  p = stockSummary(art, 5, cd, 2) ;
  printf("%s\n",p) ;
  free(p) ;
  p = NULL  ;
     // 向标准错误流输出文件，即使用户重定向了stdout.   
    fclose(fp) ;
    fp = NULL ;
    */
    fclose(fin) ;
    fclose(fout) ;
    return 0 ;
} 







void quick(int (*a)[N] , int low , int high)
{
/*
    srand((unsigned)time(NULL)) ;

    int a[N] ;
    for(int i = 0 ; i != N ; i++){
        a[i] = rand() % MOD + 1 ;
        printf("%d  ",a[i]) ;
    }
    puts("") ;
    quick( &a , 0 , N - 1) ;
    for(int i = 0 ; i != N ; ++i){
        printf("%d  ",a[i]) ;
    }
    puts("") ;
    */
    int tmp = (*a)[low] , idx = low , idx1 = high ; // caution!!!

    // 没有采用分割函数，low and high 在这个过程中被改变了， 所以在一开始
    //需要拷贝二者的值。 
     
    if(low >= high)
        return ;
    while(true){
        while(low < high && (*a)[high] >= tmp)
            high-- ;
        if(low == high)
            break ;
        (*a)[low++] = (*a)[high] ;

        while(low < high && (*a)[low] <= tmp)
            low++ ;
        if(low == high)
            break ;
        (*a)[high--] = (*a)[low] ;
    }
    (*a)[high] = tmp ;
    int pivot = high ;

    quick(a,idx,pivot - 1) ;
    quick(a,pivot + 1 , idx1) ;
}


bool PerfectNum(int number)
{
  int sum = 1 ;
  for(int i = 2 ; i * i <= number ; i++){
    if(number % i == 0){
      sum += i + number / i ;
    }
  }
  return (sum == number) ? true : false ;
}


void ReverseWrod(void)
{
    /**********************************************
    *ex : I love you .   output : you love I .    *
    ***********************************************/
    int i = 0 ;
    char *begin = NULL , *end = NULL ;
    char a[N + 1] = {0} , ch ;
    // get character string
    while((ch = getchar()) != '\n'){
        if( i < (N + 1))
            a[i++] = ch ;
        else 
            break;
    } 
    a[i] = '\0' ;
    for(int j = i - 1 ; j >= 1 ; j--){
        if(a[j] == '.' || a[j] == '?' || a[j] == ',')
            ch = a[j] ;
        else if ( a[j] != ' ' && a[j - 1] == ' '){
            begin = &a[j] ;
            do{
                printf("%c",*begin) ;
            }while(*begin++ != ' ') ;
        }
        if (a[j] == ' ')
            end = &a[j] ;
    }
    for( i = 0 ; a[i] != *end ; i++)
        printf("%c",a[i] ) ;
    printf(" %c",ch) ;


}

double PrimeSum(int n)
{
    int num, divisor ;
    bool flag = true ;
    double sum = 0.0 ;
    for( num = 3 ; num <= n ; num++ ){
        for( divisor = 2 ; divisor <= sqrt(num); divisor++ ){
            if (num % divisor == 0){
                flag = false ;
                break ;
            }
            flag = true ; // 
        }
        if (flag)
            sum += sqrt(num) ;
    }
    return sum ;
}



char *find_char(char const *source, char const *chars)
{
    while(*chars){
        while(*source){
            if (*chars == *source)
                return (char *) source ;
            source++ ;
        }
        chars++ ;
    }
    return NULL ;
}
char * match(char *str, char *want)
{
    /*
    **Keep looking while there are more characters in 'want'.
    we fall out of the loop if we get a match .
    */

    while(*want != NUL){
        if (*str++ != *want++)
            return NULL ;
    }
    return str ; // at the back of the want 
}
int del_substr(char *str ,char *substr)
{
    char *next ;
    // look through the string for the first occurrence of the substring.
    while(*str != NUL){
        next = match(str,substr) ;
        if(next != NULL)
            break ;
        str++ ;
    }
    // if we reached the end of the string , then the substring
    // was not found.

    if (*str == NUL)
        return 0 ;
    // Delete the substring by copuing the bytes after it over
    // the bytes of the substring itself .
    while(*str++ = *next++)
        ;
    return 1 ;
}

void find_two_largest(int a[] , int n , int *largest , int *second_largest) 
{   
    int i , *p , *q ;
    p = a ;
    if ( *p > *(p + 1)) {
        *largest = *p ;
        *second_largest = *(p + 1) ;
    }
    else {
        *largest = *(p + 1) ;
        *second_largest = *p ;
    }
    
    for( i = 2 ; i < n ; i++){
        q = &a[i] ;
        if ( *q > *largest ){
            *second_largest = *largest ;
            *largest = *q ;
        }
        else if ( *q > *second_largest)
            *second_largest = *q ;
    }
}
