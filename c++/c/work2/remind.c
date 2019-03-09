#include <stdio.h>
#include <string.h>
#define MAX_REMIND 100
#define MSG_LEN 100

int read_line( char str[] , int n ) ;


int main(void)
{
	char *reminders[MAX_REMIND];

	char day_str[3] , msg_str[MSG_LEN + 1] ;

	char tes_str[3];

	int day , i , j , num_remind = 0  ;

	while( 1 ) {

		if ( num_remind == MAX_REMIND ){

			printf("--No space left --\n") ;

			break ;

		}


		printf("Enter date and reminder :  ") ;

		scanf("%2d",&day) ;

		if ( day == 0 )

			break ;

		sprintf(day_str,"%2d",day) ; //库函数，把day的值写入字符串中，并自动添加一个空字符。

		read_line(msg_str,MSG_LEN) ;


		for( i = 0 ; i < num_remind ; i++ )

			if ( strcmp( day_str , reminders[i] ) < 0 )

				break ;

		for ( j = num_remind ; j > i ; j-- )

			reminders[j] = reminders[j - 1] ;

		reminders[i] = malloc( 2 + strlen(msg_str) + 1) ;

		if ( reminders[i] == NULL ){

			printf("--No space left --\n") ;
			break ;
		}


		strcpy(reminders[i] ,day_str) ;

		strcat(reminders[i] ,msg_str) ;

		num_remind++ ;


	}


	printf("\nDay Reminder\n") ;

	for ( i = 0 ; i < num_remind ; i++ )

		printf("%s\n",reminders[i] ) ;

	/*while( 1 ){
	
		scanf("%2d",&day) ;

		sprintf(day_str,"%2d",day) ;


		for( i = 0 ; i < num_remind ; i++ ) {

			sprintf(tes_str,"%2s",reminders );

			if ( strcmp(day_str, tes_str) == 0 ) {

				printf("%s\n",reminders[i] ) ;
				
				break ;
			}

		}

		if (day == 0 )

			break ;
	
	}
	*/
	

	return 0 ;

}

int read_line(  char str[] , int n )

{

	int ch , i ; 

	for ( i = 0 ; (ch = getchar()) != '\n' ; )

		if ( i < n )

			str[i++] = ch ;

	str[i] = '\0' ;

	return i ;

}