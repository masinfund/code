#ifndef _DATE_H_
#define _DATE_H_


class Date {
private:
	int year ;
	int month ;
	int day ;
	int totalDays ;
	//static Date default_date ;
public :
	
	// enum Month{jan = 1 , feb , mar , apr , may , jun , jul , aug , sep ,oct , nov , dec } ;
	// class Bad_date() ;
	// std::string string_rep() const ;
	// void char_rep(char *s) const ;
	// static void set_default(int , Month , int) ; 

	Date(int year = 1 , int month = 1 , int day = 1) ;
	int getYear() const {return year ;}
	int getMonth() const {return month ;}
	int getDay() const {return day ;}
	int getMaxDay() const ;  // 获得当月的天数
	bool isLeapYear() const {
		return year % 4 == 0 && year % 100 != 0 || year % 400 == 0 ;
	}
	void show() const ;
	int distance(const Date &date) const {
		return totalDays - date.totalDays ;
	}
};

#endif 
