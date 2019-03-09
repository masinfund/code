#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COLS 20 // 所能处理的最大列号
#define MAX_INPUT 1000  // 每个输入行的最大长度
using namespace std; 





int read_col_num(int *col , int max) ;
void rearrange(char* output , char const *input , int n_col , int const *col);
void col_operate()
{
		int n_col ; // 列标号
	int columns[MAX_COLS] ; // 需要处理的列数
	char input[MAX_INPUT];
	char output[MAX_INPUT] ;

	// 读取串列标号 
	n_col = read_col_num(columns , MAX_COLS) ;

	// 读取、处理和打印剩余的输入行
	while(gets(input)){
		printf("Original input : %s\n",input) ;
		rearrange(output , input , n_col , columns) ;
		printf("rearranged line : %s \n", output) ;
	}
}

int main()
{
	// col_operate() ;


	return EXIT_SUCCESS ;	
 } 




//读取列标号，如果超出范围则
int read_col_num(int *col , int max) 
{
	int num = 0 ; 
	int ch ;

	while(num < max && scanf("%d",&col[num]) == 1 
		  			&& col[num] >= 0)
		num++ ;

	if(num % 2 ){
		puts("Last column number is not paired.") ;
		exit(EXIT_FAILURE) ;
	}

	while((ch = getchar()) != EOF && ch != '\n')
		 ; 
	return num ;

}

// 处理输入行 ， 将指定列的字符连接在一起 
void rearrange(char* output , char const *input ,
			   int n_col , int const *col){

	int col_idx ; // col 数组的下标 
	int output_col ;
	int len ;

	len = strlen(input) ;
	output_col = 0 ;

	// 处理每对列标号
	for(col_idx = 0 ; col_idx < n_col ; col_idx += 2){
		int nchars = col[col_idx + 1] - col[col_idx] + 1 ;
		
		if(col[col_idx] >= len || output_col == MAX_INPUT - 1)
			break ;

		// 如果输出行数据空间不够 ， 只复制可以容纳的数据
		if(output_col + nchars > MAX_INPUT - 1)
			nchars = MAX_INPUT - output_col - 1 ;

		strncpy(output + output_col , input + col[col_idx] , nchars) ;
		output_col += nchars ;
	}
	output[output_col] = '\0' ;	
}

