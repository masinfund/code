#ifndef _POINT_H
#define _POINT_H
#include <iostream>
#include <vector>

class Point {
	friend double distance(const Point &p1 , const Point &p2) ;
	friend double LineFit(const std::vector<Point> &points) ;
	//friend std::istream& read(std::istream& , Point &) ;
	public : 
		Point(const int x = 0 ,const int y = 0) : x(x) ,y(y) {
			Pcount++ ;
		}
		//Point(std::istream &is) {read(is,*this) ; count++ ;}
		Point (const Point &p) ;
		~Point() {
			Pcount-- ;
		}
		
		int getX() const {return x ;}
		int getY() const  {return y ;}
		void move(int offsX , int offsY){ x += offsX ; y += offsY ;}
		void initPoint(int X = 0 , int Y = 0){
			x = X ;
			y = Y ;
		}
		static void showCount() ;
		void show() ;
	private :
		int x , y ;
		static int Pcount ;
		
} ;




class Rectangle : public Point {
	public :
		void initRectangle(int x , int y , int w , int h){
			initPoint(x,y) ;
			width = w ;
			high = h ;
		}
		int getH() const {return high ;}
		int getW() const {return width ;}
	private:
		int width , high ;
} ;


















double distance(const Point &p1, const Point &p2) ;
double LineFit(const std::vector<Point> &points) ;
//std::istream& read(std::istream& , Point &) ;

#endif 