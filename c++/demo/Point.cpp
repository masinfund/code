#include "stdafx.h"

using namespace std ;
int Point::Pcount =  0 ;

Point::Point(const Point &p)
{
	x = p.x ;
	y = p.y ;
	Pcount++ ;
		
}

double distance(const Point &p1, const Point &p2) 
{
	double x = p1.x - p2.x ;
	double y = p1.y - p2.y ;
	return static_cast<double> (sqrt(x * x + y * y)) ;

}


void Point::showCount() 
{
	cout << Pcount  << endl ;
}

void Point::show() {
	cout << "(" << x << " , " << y << ") Point number is  : " <<  Pcount << endl ;
}

/*
std::istream &read(std::istream &is , Point &rs) 
{
	is >> x >> y ;
	return is ;
}*/
double LineFit(const vector<Point> &points) 
{
	// 曲线拟合 
	double avgX = 0 , avgY = 0 ;
	double lxx = 0 , lyy = 0 , lxy = 0 ;
	for( vector<Point>::size_type i = 0 ; i != points.size() ; ++i){
		avgX += points[i].getX() / points.size();
		avgY += points[i].getY() / points.size() ;
	}
	for(decltype(points.size()) i = 0 ; i != points.size() ; ++i){
		lxx += (points[i].getX() - avgX) * (points[i].getX() - avgX) ;
		lyy += (points[i].getY() - avgY) * (points[i].getY() - avgY) ;
		lxy += (points[i].getX() - avgX) * (points[i].getY() - avgY) ;	
	}
	cout << "This line can be fitted by y = a * x + b ." << endl ;
	cout << "a = " << (lxy / lxx) << "    " ;
	cout << "b = " << (avgY - lxy * avgX / lxx) << endl ;
	return static_cast<double> (lxy / sqrt(lxx * lyy)) ;

}