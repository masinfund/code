#ifndef _ACCUMULATOR_H_
#define _ACCUMULATOR_H_

#include "stdafx.h"


class Accumulator{
private:
	Date lastDate ; // 上次变更数值的日期
	double value ;  //数值的当前值
	double sum ;  // 数值按日累加值
public:
	Accumulator(const Date &date , double value) : 
	lastDate(date) , value(value) , sum(0) {} 

	//获得日期date 的累加结果
	double getSum(const Date &date) const {
		return sum + value * date.distance(lastDate) ;
	}

	// 改变Date的数值为value 
	void change(const Date &date , double value) {
		sum = getSum(date) ;
		lastDate = date ;
		this->value = value ;
	}

	// 初始化，将日期变为date , 数值变为value，累加器清零
	void reset(const Date &date , double value) {
		lastDate = date ;
		this->value = value ;
		sum = 0 ; 
	}
};

#endif 

