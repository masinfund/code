#include "stdafx.h"

int main()
{
	
	Date date(2008 , 11 , 1) ;
	Account accounts[] = {Account(date , "道德" ,0.015) , Account(date,"张三",0.015)} ;
	accounts[0].deposit(Date(2008,11,5) , 5000 , "Salary") ;
	accounts[1].deposit(Date(2008,11,25),10000,"Sell stock 0323") ;
	accounts[0].deposit(Date(2008,12,5) ,5500 ,"Salary") ;
	accounts[1].withdraw(Date(2008,12,20) ,4000,"Buy alaptop") ;
	cout << endl ;
	for(int i = 0 ; i < static_cast<int >(sizeof(accounts) / sizeof(Account)) ; ++i){
		accounts[i].settle(Date(2009,1,1)) ;
		accounts[i].show() ;
	} 
	cout << "Total : " << Account::getTotal() << endl ;

	return 0 ;
}