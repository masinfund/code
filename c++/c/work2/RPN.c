#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

/*

void InitStack(LiStack *s) ;
int Isempty(LiStack *s) ;
void Destroy(LiStack *s) ;
ElemType Pop(LiStack *s) ;
void Push(LiStack *s , ElemType item) ;
中缀表达式转后缀表达式 ： 
	ex : 9 + (3 - 1) * 3 + 10 / 2   to    9 3 1 - 3 * + 10 2 / + 
	规则 ： 从左到右遍历中缀表达式的每个数字和符号， 若是数字则输出 ；
			 若是符号则判断其与栈顶符号的优先级 ， 是右括号或优先级
			 低于栈顶符号则栈顶元素依次出栈并输出 ，并将当前符号进栈。



*/

int priority(LiStack *s , int ch){
	int *tmp = top(s) ;
	if(!tmp ){
		return -1 ;
	}
	switch(ch){
		case '+' : case '-' : 
			if(*tmp == '+' || *tmp == '-' )
				return 0 ;
			else 
				return 1 ;
			break ;
		case '*' : case '/' : case '%' :
			if(*tmp == '*' || *tmp == '/' || *tmp == '%')
				return 1 ;
			else
				return -1 ;
			break ;
		case '(' : 
			return -1 ;
			break ;
		case ')' :
			return 2;
			break ;
		default :
			return -1 ;
			//sprintf(stderr, "character match wrong ! ") ;
			break ;
	}
}

int main(void) 
{
	LiStack s , s1 ;
	//stack test 
	InitStack(&s) ;
	InitStack(&s1) ;
	for(int i = 1 ; i <= 4 ; ++i){
		Push(&s,i) ;
	}
	while(!Isempty(&s)){
		printf("%d " ,Pop(&s)) ;
	}
	puts("") ;
	const int N = 100 ;


	//中转后
	char ch ;
	while(scanf(" %c", &ch) != EOF){
		if(ch >= '0' && ch <= '9'){
			Push(&s1 , ch);
			continue ;
		}
		else{
			Push(&s1,' ') ;
			switch(priority(&s ,ch)){
				case -1 :
					Push(&s , ch) ;
					break ;
				case 0 :
					Push(&s1 , Pop(&s)) ;
					Push(&s1,' ') ;
					Push(&s , ch) ;
					break ;
				case 1 :
					Push(&s1 ,Pop(&s)) ;
					while(priority(&s , ch) == 0){
						Push(&s1,' ') ;
						Push(&s1 , Pop(&s)) ;
					} 
					Push(&s1,' ') ;
					Push(&s , ch) ;
					break ;
				case 2 :
					while( *top(&s) != '('){
						Push(&s1 , Pop(&s)) ;
					}
					Pop(&s) ;
					break ;
				default :
					break ;
			} 
		}
		
	}
	while(!Isempty(&s)){
		Push(&s1, Pop(&s)) ;
	}
	while(!Isempty(&s1)){
		Push(&s, Pop(&s1)) ;
	}


// calculator 
	int tmp = 0 ,sum = 0 , a = 0 , flag = 0 ; 
	if(*top(&s) == ' ')
		Pop(&s) ;
	while(!Isempty(&s)){
		printf("%c", tmp = Pop(&s)) ;
		while(tmp >= '0' && tmp <= '9'){
			if(!flag){
				sum *= 10 ;
				sum += tmp - '0' ;
			}
			else{
				a *= 10 ;
				a += tmp - '0' ;
				flag = 2 ;
			}
			printf("%c",tmp = Pop(&s)) ;
		}
		if(flag == 2){
			flag = 1 ;
			Push(&s1, a) ;
			a = 0 ;
		}
		if(tmp == ' ' && !flag){
			flag = 1 ;
			Push(&s1 , sum) ;
			sum = 0 ;
		}
		if(tmp == '+' || tmp == '-' || tmp == '*' || tmp == '/'){
			a = Pop(&s1) ;  
			sum = Pop(&s1) ;
			switch(tmp){
				case '+' :
					sum += a ;	a = 0 ;	    break ;
				case '-' :
					sum -= a ;	a = 0 ; 	break ;
				case '*' :
					sum *= a ;	a = 0 ; 	break ;
				case '/' :
					sum /= a ;	a = 0 ; 	break ;
			}
			Push(&s1 , sum) ;
		}

	}
	sum = Pop(&s1) ;
	printf("\nthe operation is %d.\n", sum ) ;

	Destroy(&s) ;
	Destroy(&s1) ;



	return 0 ;
}