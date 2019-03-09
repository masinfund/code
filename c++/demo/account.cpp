#include "stdafx.h"


double Account::total = 0 ;

Account::Account(const Date& date , const string& id ) :
	id(id) , balance(0)
{
 	date.show() ;
 	cout << "\t#" << id << "\tcreated"<< endl ;
}

void Account::record(const Date& date , double amount, const string &desc) {
	amount = floor( amount * 100 + 0.5) / 100 ; // 保留小数点后两位
	balance += amount ;
	total += amount ;
	date.show() ;
	cout << "\t#" << id << "\t" << amount << "\t" << balance << "\t" << desc << endl ;
}

void Account::show() const {
	cout << "#" << id << "\tBalance : " << balance << endl ;
}
void Account::error(const string& msg) const {
	cout << "Error(#" << id << "): " << msg << endl ;
}




// savingAccount 
savingAccount::savingAccount(const Date &date , const std::string &id , double rate) :
	Account(date , id) , rate(rate) , acc(date , 0) { }

void savingAccount::deposit(const Date& date , double amount , const std::string &desc) {
		record(date,amount ,desc) ;
}

void savingAccount::withdraw(const Date& date , double amount , const string &desc){
	if(amount > getBalance()) {
		error("not enough money") ;
	}
	else 
		record(date, -amount , desc) ;
}
	
	// settlement interest , every year the first month first day 
void savingAccount::settle(const Date& date) {
	double interest = acc.getSum(date) * rate / date.distance(Date(date.getYear() - 1 ,1,1));
	if(interest != 0){
		record(date,interest ,"interest") ;
	}
	acc.reset(date , getBalance()) ;
}



// creditAccount 

creditAccount::creditAccount(const Date &date , const std::string &id , double credit , double rate , double fee) : 
	Account(date , id) , credit(credit) , rate(rate) , fee(fee) , acc(date,0) { }


void creditAccount::deposit(const Date &date , double amount , const std::string &desc){
	record(date , amount , desc) ;
	acc.change(date , getDebt()) ;
}

void creditAccount::withdraw(const Date &date , double amount , const std::string &desc){
	if(amount getBalance() > credit) {
		error("not enough credit") ;
	}
	else {
		record(date , -amount , desc) ;
		acc.change(date , getDebt()) ;
	}
}

void creditAccount::settle(const Date &date){
	double interest = acc.getSum(date) * rate ;
	if(date.getMonth() == 1) { record(date , -fee , "annual fee") ;}
	acc.reset(date , getDebt()) ;
}
	void creditAccount::show() const {
		Account::show() ;
		cout << "\tAvailable credit : " << getAvailableCredit() << endl ;
	}



