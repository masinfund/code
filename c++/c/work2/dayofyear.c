#include <stdio.h>

void day_of_year( int month , int day , int year) ;

int main(void) 
{
	int month , day , year ;


	printf("Enter the date :(month/day/year) ") ;

	scanf("%d/%d/%d/",&month,&day,&year) ;
	
	day_of_year(month,day,year);



	return 0 ;

}

void day_of_year( int month , int day , int year )
{

	if ( ( year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0 ) ) 

		switch(month) {

			case 1 : 	case 3 : 	case 5 : 	

			case 7 : 	case 8 :	case 10 : 	case 12 :

				printf("The %dth day of %d",month * 31 + day , year)  ;

				break ;

			case 2 :

				printf("%he %dth day of %d",month * 29 + day , year) ;

				break ;


			case 4 : 	case 6 : 	case 9 : 	case 11 : 

				printf("The %dth day of %d",month * 30 + day , year ) ;

				break ;
			default :

				printf("WRONG!\n");

				break ;

		}

	else 

			switch(month) {

			case 1 : 	case 3 : 	case 5 : 	

			case 7 : 	case 8 :	case 10 : 	case 12 :

				printf("The %dth day of %d",month * 31 + day , year)  ;

				break ;

			case 2 :

				printf("%he %dth day of %d",month * 28 + day , year) ;

				break ;

			case 4 : 	case 6 : 	case 9 : 	case 11 : 

				printf("The %dth day of %d",month * 30 + day , year ) ;

				break ;

			default :

				printf("WRONG!\n");

				break;



		}



}