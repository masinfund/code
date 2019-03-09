#include "stdafx.h"

/*
	计算两个日期相差得天数 
	f(y/m/d,1/1/1) = f(y/1/1,1/1/1) + f(y/m/1,y/1/1) + f(y/m/d,y/m/1) 
	f(y/1/1,1/1/1) = 365 * (y - 1) + floor((y - 1) / 4) - floor((y - 1) / 100)
					 + floor((y - 1) / 400)
	f(y/m/1,y/1/1) = (m > 2) ? ((m - 1) * monthSum) : (isleapYear(m) ? (m - 1) * 29 : (m - 1) * 28)
	f(y/m/d,y/m/1) = d - 1 

*/

namespace {
	const int DAYS_BEFORE_MONTH[] = {0,31,59,90,120,151,181,212,243,273,304,334,365} ;
}

Date::Date(int year, int month , int day) : year(year) , month(month),day(day) {
	if(month < 1 || month > 12 || day <= 0 || day > getMaxDay()) {
		cout << "Invalid date : " ;
		show() ;
		cout << endl ;
		exit(EXIT_FAILURE) ;
	}
	int years = year - 1;
	totalDays = years * 365 + years / 4 - years / 100 + years / 400 
				+ DAYS_BEFORE_MONTH[month - 1] + day ;
	if(isLeapYear() && month > 2) totalDays++ ;	
}

int Date::getMaxDay() const {
	if(isLeapYear() && month == 2)
		return 29 ;
	else 
		return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1] ;
}

void Date::show() const {
	cout << getYear() << "-" << getMonth() << "-" << getDay() ;
}

