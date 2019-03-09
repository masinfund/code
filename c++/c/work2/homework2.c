#include <stdio.h>
#define N 5

int sum_row( int a[][N] , int n ) ;

int sum_column( int a[][N] , int x ) ;


int main(void)
{

	//ctrl+z是结束stdin，ctrl+c是向进程发送SIGINT（中断信号）

	/*======================================
	Windows中的回车与还行
	'\r'是回车，前者使光标到行首，（carriage return）
    '\n'是换行，后者使光标下移一格，（line feed
	\r 回车 就是return 回到 本行 行首
	\r\n 换行 把光标先移到行首然后换到下一行 也就是 下一行的行首拉
	1、windows下可直接使用\n来匹配换行符，但仍然推荐使用标准的\r\n来匹配键盘Enter键的换行符;
	
	2、使用\r\n组合是有顺序的，调转顺序写成\n\r是错误的，将无法匹配换行符！
	'\n':? UNIX 系统行末结束符
	"\r\n": window 系统行末结束符
	'\r':? MAC OS 系统行末结束符
	// \b不能清除已打印字符 ,backspace 退格以待继续打印
	======================================*/

	int i , n ,cnt , j  ,average ,sum = 0 ,high , low ,average_course ;

	int a[5][5]  ;

	char ch ;

	printf("This program prints a tabale of squares .\n") ;

	printf("Enter number of entries in table :")  ;

	scanf("%d",&n) ;

	for ( i = 1 , cnt = 1 ; i <= n ; i++ , cnt++ ) {
	
		printf("%10d%10d\n",i,i * i ) ;

		if ( cnt % 24 == 0 ) {

			printf("Press Enter to continue...") ;

			do{
			
				scanf("\n%c",&ch) ;
			
			} while ( ch != '\n') ;
		

		}

	}

	// Compute the sum of each column and row 

	average = 0 ;

	for ( i = 1  ; i <= N ; i++  ){

		printf("Enter student %d : ", i) ;

		for ( j = 0 ; j < N  ; j++ ){

		    scanf("%d",&n) ;

		    a[i-1][j] = n ;

		}


	}

	printf("\n\nThe total score of all students :    ") ;


	for ( i = 0 ; i < N ; i++ ){

		printf("%2d  ",sum_row(a , i));

		sum +=sum_row(a , i ) ;


	}

	average = sum / N ;

	printf("The average score of all students :    %d",average) ;

	printf("\nThe average score of every course :  ") ;

	for ( i = 0 ; i < N ; i++){

		average_course = sum_column( a , i) / N ;

		printf("%2d  ",average_course ) ;

	}
	printf("\n");

	return  0 ;

	
}


int sum_row( int a[][N] , int n ) 

{
	int sum , i ;

	for ( i = 0 , sum = 0 ; i < N ; i++)
	
		sum += a[n][i] ;	


	return sum ;

}

int sum_column ( int a[][N] , int x ) 

{

	int sum , i ; 

	for ( i = 0 , sum = 0 ; i < N ; i++)


		sum += a[i][x] ;

	
	return sum ;


}