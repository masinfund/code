#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20 
int main(void) 
{
	char word[MAX_WORD_LEN + 2] ;
	int word_len ;
	clear_line() ;
	// justify <D:\\code\\c\\work2\\in.dat   at cmd is valid
	//这里“ > ”表示覆盖式输出，而“ >>  ” 表示追加式输出
	for(; ; ) {
		word_len = read_word(word, MAX_WORD_LEN + 1) ;
		if( word_len == 0 ){
			flush_line() ;
			return 0 ;
		}
		if(word_len > MAX_WORD_LEN) 
			word[MAX_WORD_LEN] = '*' ;
		if(word_len + 1 > space_remaining() ) {
			write_line() ;
			clear_line() ;
		}
		add_word(word) ;
	}
}