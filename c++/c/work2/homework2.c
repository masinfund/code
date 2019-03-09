#include <stdio.h>
#define N 5

int sum_row( int a[][N] , int n ) ;

int sum_column( int a[][N] , int x ) ;


int main(void)
{

	//ctrl+z�ǽ���stdin��ctrl+c������̷���SIGINT���ж��źţ�

	/*======================================
	Windows�еĻس��뻹��
	'\r'�ǻس���ǰ��ʹ��굽���ף���carriage return��
    '\n'�ǻ��У�����ʹ�������һ�񣬣�line feed
	\r �س� ����return �ص� ���� ����
	\r\n ���� �ѹ�����Ƶ�����Ȼ�󻻵���һ�� Ҳ���� ��һ�е�������
	1��windows�¿�ֱ��ʹ��\n��ƥ�任�з�������Ȼ�Ƽ�ʹ�ñ�׼��\r\n��ƥ�����Enter���Ļ��з�;
	
	2��ʹ��\r\n�������˳��ģ���ת˳��д��\n\r�Ǵ���ģ����޷�ƥ�任�з���
	'\n':? UNIX ϵͳ��ĩ������
	"\r\n": window ϵͳ��ĩ������
	'\r':? MAC OS ϵͳ��ĩ������
	// \b��������Ѵ�ӡ�ַ� ,backspace �˸��Դ�������ӡ
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