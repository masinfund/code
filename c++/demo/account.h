#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include "stdafx.h"

class Account {
	private :
		std::string id ; // 用户名
		double balance ; // 余额
		static double total ; // 所有账户的总金额

	protected:
		
		// 供派生类调用的构造函数，id为账户
		Account(const Date &date , const std::string &id) ;
		
		//记录一笔账，desc为说明
		void record(const Date &date , double amount ,const std::string &desc ) ;
		void error(const std::string &msg) const ; // 报告错误信息
	
	public : 

		const std::string& getId() const {return id ;}
		double getBalance() const  {return balance ;} 
		static double getTotal() {return total ;} // no const static func  
		void show() const ;   // 显示账户信息   
} ;

class savingAccount : public Account {
private:
	Accumulator acc ;
	double rate ;    // 年利率
public:
		//double accumulate(const Date& date ) const  ;//获得到指定日期为止的存款金额按日累积量
	SavingAccount(const Date &date , const std::string &id , double rate) ;
	double getRate() const {return rate ;}
	void deposit(const Date& date , double amount , const std::string &desc) ;
	void withdraw(const Date& date , double amount , const std::string &desc) ;
	
	// settlement interest , every year the first month first day 
	void settle(const Date& date ) ;
} ;



class creditAccount : public Account{
private:
	Accumulator acc ; // 辅助计算利息的累加器
	double credit ;   //信用额度
	double rate ;  // 欠款的日利率 
	double fee ; // 信用卡年费
	double getDebt() const { double balance = getBalance() ; return balance < 0 ? balance : 0 ; } // 获得欠款额
public :
	creditAccount(const Date &date , const std::string &id , double credit , double rate , double fee) ;
	double getCredit() const {return credit ;}
	double getRate() const {return rate ; }
	double getFee() const {return fee ;}
	double getAvailableCredit() const { return ( getBalance() < 0) ? credit + getBalance() : credit ;  }

	void deposit(const Date &date , double amount , const std::string &desc) ;
	void withdraw(const Date &date , double amount , const std::string &desc) ;
	void settle(const Date &date) ;
	void show() const ;
} ;


#endif 