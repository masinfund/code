#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 5

/* external variables */

int num_in_rank[NUM_RANKS] ;
int num_in_suit[NUM_SUITS] ;
bool straight , flush ,four ,three ;
int pairs ; /*can be 0,1,or 2 */


//prototypes
void read_cards(void) ;
void analyze_hand(void) ;
void print_result(void) ;

int main(void) 
{
	/***************************************************
	 * main : Calls read_cards , analyze_hand , and    *
	 * print_result repeatedly .                       *
	 **************************************************/
	for ( ; ; ){
		read_cards() ;
		analyze_hand() ;
		print_result() ;

	}
	/*
	const char rank_code[] = {'2','3','4','5','6','7','8','9','10','J','Q','K','A' } ;

	//梅花 club 方块 diamond 红桃 heart 黑桃 spade

	const char suit_code[] = {'c','d','h','s'} ;


	srand((unsigned) time (NULL) ) ; 
	
	//Seed the random-number generator with current time.
	//so that the numbers will be different every time when we run. 

	printf("Enter number of cards in hand :") ;

	scanf("%d",&num_cards) ;

	printf("Your hand :\n") ;

	for ( ; num_cards > 0 ; num_cards--) {

		suit = rand() % NUM_SUITS ;

		rank = rand() % NUM_RANKS ;

		if ( ! in_hand[suit][rank]) 

			in_hand[suit][rank] = TRUE ;

		printf("	%c%c",rank_code[rank] , suit_code[suit]) ;
		
		if ( num_cards % 7 == 0 ) 
		
			printf("\n") ;

	}

	
	printf("\n") ;

	*/

	return 0 ;

}

void read_cards(void)
{
	bool card_exits[NUM_RANKS][NUM_SUITS] ;
	char ch , rank_ch , suit_ch ;
	int rank , suit ;
	bool bad_card ;
	int cards_read = 0 ;

	for (rank = 0 ; rank < NUM_RANKS ; rank++){
		num_in_rank[rank] = 0 ;
		for ( suit = 0 ; suit < NUM_SUITS ; suit++)
			card_exits[rank][suit] = false ;
	}

	for ( suit = 0 ; suit < NUM_SUITS ; suit++)
		num_in_suit[suit] = 0 ;

	while( cards_read < NUM_CARDS ) {
		bad_card = false ;

		printf("Enter a card : ") ;

		rank_ch = getchar() ;
		switch (rank_ch) {
			case '0' : exit(EXIT_SUCCESS) ;
			case '2' : rank = 0 ; break ;
			case '3' : rank = 1 ; break ;
			case '4' : rank = 2 ; break ;
			case '5' : rank = 3 ; break ;
			case '6' : rank = 4 ; break ;
			case '7' : rank = 5 ; break ;
			case '8' : rank = 6 ; break ;
			case '9' : rank = 7 ; break ;
			case 't' : case 'T' : rank = 8 ; break ;
			case 'j' : case 'J' : rank = 9 ; break ;
			case 'q' : case 'Q' : rank = 10 ; break ;
			case 'k' : case 'K' : rank = 11 ; break ;
			case 'a' : case 'A' : rank = 12 ; break ;
			default : bad_card = true ;
		}

		suit_ch = getchar() ;
		switch (suit_ch) {
			case 'c': case 'C' : suit = 0 ; break ;
			case 'd': case 'D' : suit = 1 ; break ;
			case 'h': case 'H' : suit = 2 ; break ;
			case 's': case 'S' : suit = 3 ; break ;
			default : bad_card = true ;
		}

		while( (ch = getchar() ) != '\n' )
			if (ch != ' ' )
				 bad_card = true ;

		if ( bad_card)
			printf("Bad card; ignored.\n") ;
		else if ( card_exits[rank][suit] ) 
			printf("Duplicate card ; ignored.\n") ;
		else {
			num_in_suit[suit]++ ;
			num_in_rank[rank]++ ;
			card_exits[rank][suit] = true ;
			cards_read++ ;
		}
	}
}
/********************************************************
 * analyze_hand : Determines whether the hand contains  *
 *				  a straight, a flush , four-of-a-kind, *
 *				  and/or three-of-a-kind;determines the *
 *				  number of pairs;stores the results    *
 *				  into the external variables straight, *
 *				  flush, four,three,and pairs.          *
 ********************************************************/

void analyze_hand(void)
{
	int num_consec = 0 ;
	int rank , suit ;

	straight = false ;
	flush = false ;
	four = false ;
	three = false ;
	pairs = 0 ;

	/* check for flush */

	for( suit = 0 ; suit < NUM_SUITS ; suit++)
		if ( num_in_suit[suit] == NUM_CARDS)
			flush = true ;
	
	/* check for straight */
		
		rank = 0 ;
		
		while( num_in_rank[rank] == 0)
			rank++ ;
		for( ; rank < NUM_RANKS && num_in_rank[rank] > 0 ; rank++)
			num_consec++ ;
		if ( num_consec == NUM_CARDS ) {
			straight = true ;
			return ;

		}

		/* check for 4-of-a-kind, 3-of-a-kind, and pairs */

		for( rank = 0 ; rank < NUM_RANKS ; rank++) {

			if (num_in_rank[rank] == 4 ) 
				four = true ;
			if ( num_in_rank[rank] == 3 )
				three = true ;
			if ( num_in_rank[rank] == 2 )
				pairs++ ;
		}
}

void print_result(void)
{

	if ( straight && flush )
		printf("Straigh flush") ;
	else if( four)
		printf("Four of a kind");
	else if( three && pairs == 1)
		printf("Full house") ;
	else if( flush )
		printf("Flush") ;
	else if ( straight )
		printf("straight");
	else if ( three )
		printf("Three of a kind ") ;
	else if ( pairs == 2)
		printf("Two pairs") ;
	else if ( pairs == 1)
		printf("Pair") ;
	else
		printf("High card") ;
	printf("\n\n") ;
}
/*
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>

#define NUM_CARDS 5
#define RANK 0
#define SUIT 1

int hand[NUM_CARDS][2] ;
bool straight,flush ,four ,three ;
int pairs ;

void read_cards(void) ;
void analyze_hand(void);
void print_result(void) ;

int main(void)

{	
	for ( ; ; ) {
		read_cards() ;
		analyze_hand() ;
		print_result() ;
	}
  
    return 0 ;
}


void read_cards(void)
{
	char rank_ch , suit_ch, ch ;
	int i ,rank , suit ;
	bool bad_card , duplicate_card ;
	int cards_read = 0 ;

	while( cards_read < NUM_CARDS ) {
		bad_card = false ;

		printf("Enter a card : ") ;

		rank_ch = getchar() ;
		switch (rank_ch) {
			case '0' : exit(EXIT_SUCCESS) ;
			case '2' : rank = 0 ; break ;
			case '3' : rank = 1 ; break ;
			case '4' : rank = 2 ; break ;
			case '5' : rank = 3 ; break ;
			case '6' : rank = 4 ; break ;
			case '7' : rank = 5 ; break ;
			case '8' : rank = 6 ; break ;
			case '9' : rank = 7 ; break ;
			case 't' : case 'T' : rank = 8 ; break ;
			case 'j' : case 'J' : rank = 9 ; break ;
			case 'q' : case 'Q' : rank = 10 ; break ;
			case 'k' : case 'K' : rank = 11 ; break ;
			case 'a' : case 'A' : rank = 12 ; break ;
			default : bad_card = true ;
		}

		suit_ch = getchar() ;
		switch (suit_ch) {
			case 'c': case 'C' : suit = 0 ; break ;
			case 'd': case 'D' : suit = 1 ; break ;
			case 'h': case 'H' : suit = 2 ; break ;
			case 's': case 'S' : suit = 3 ; break ;
			default : bad_card = true ;
		}

		while( (ch = getchar() ) != '\n' )
			if (ch != ' ' )
				 bad_card = true ;

		if (bad_card) {
			printf("Bad card ; ignored.\n") ;
			continue ;
		}
		duplicate_card = false ;
		for( i = 0 ; i < cards_read ; i++)
			if ( hand[i][RANK] == rank && hand[i][SUIT] == suit ){
				printf("Duplicate card; ignored.\n") ;
				duplicate_card = true ;
				break ;
			}

		if ( !duplicate_card){
			hand[cards_read][RANK] = rank ;
			hand[cards_read][SUIT] = suit ;
			cards_read++ ;
		}

	}
}

void analyze_hand(void)
{
	int rank , suit , card , pass , run ;

	straight = true ;
	flush = true ;
	four = false ;
	three = false ;
	pairs = 0 ;

	//sort cards by rank 

	for( pass = 1 ; pass < NUM_CARDS ; pass++)
		for( card = 0 ; card < NUM_CARDS - pass ; card++){
			rank = hand[card][RANK] ;
			suit = hand[card][SUIT] ;
			if ( hand[card + 1][RANK] < rank ){
				hand[card][RANK] = hand[card + 1][RANK] ;
				hand[card][SUIT] = hand[card + 1][SUIT] ;
				hand[card + 1][RANK] = rank ;
				hand[card + 1][SUIT] = suit ;
			}
		}
		//check for flush 
	suit = hand[0][SUIT] ;
	for ( card = 1 ; card < NUM_CARDS ; card++)
		if( hand[card][SUIT] != suit) 
			flush = false ;

		// check for straight 
	for( card = 0 ; card < NUM_CARDS - 1; card ++ )
		if ( hand[card][RANK] + 1  != hand[card + 1][RANK] )
			straight = false ;

		// check for 4-of-a-kind , 
		
	card = 0 ; 
	while( card < NUM_CARDS) {
		rank = hand[card][RANK] ;
		run = 0 ;
		do {
			run++ ;
			card++ ;
		}while(card < NUM_CARDS &&hand[card][RANK] == rank ) ;

		switch(run){
			case 2 : pairs++ ; break ;
			case 3 : three = true ; break ;
			case 4 : four = true ; break ;

		}
	}


	*******************************************************
	for ( pass = 0 ;  pass < NUM_CARDS - 1 ; pass++ )
		
		for(card = pass + 1; card < NUM_CARDS ; card++ ){
			if( hard[card][RANK] < hand[pass][RANK] ){
                rank = hand[pass][RANK] ;
		        suit = hand[PASS][SUIT] ;
				hand[pass][RANK] = hand[card][RANK] ;
				HAND[pass][SUIT] = hand[card][SUIT] ;
				hand[card][RANK] = rank;
				hand[card][SUIT] = suit ;
			}

		}
	********************************************************

}

void print_result(void)
{

	if ( straight && flush )
		printf("Straigh flush") ;
	else if( four)
		printf("Four of a kind");
	else if( three && pairs == 1)
		printf("Full house") ;
	else if( flush )
		printf("Flush") ;
	else if ( straight )
		printf("straight");
	else if ( three )
		printf("Three of a kind ") ;
	else if ( pairs == 2)
		printf("Two pairs") ;
	else if ( pairs == 1)
		printf("Pair") ;
	else
		printf("High card") ;
	printf("\n\n") ;
}
*/