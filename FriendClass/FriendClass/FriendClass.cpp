// friend class
#include <iostream>
using namespace std;

class Square;

class Rectangle {
	int width, height;
public:
	int area()
	{
		return (width * height);
	}
	void convert(Square a);
};

class Square {
	friend class Rectangle;
	friend void op();
private:
	int dup(int a);
	int side;
public:
	int x;
	Square(int a) : side(a) {}
};



int Square::dup(int a)
{
	cout << "Hey" << endl;
	side = 10;
}
void Rectangle::convert(Square a) {

	width = a.side;
	height = a.side;
}

int main() {
	Rectangle rect;
	Square sqr(4);
	Square::x = 10;
	rect.convert(sqr);
	cout << rect.area();
	
	return 0;
}