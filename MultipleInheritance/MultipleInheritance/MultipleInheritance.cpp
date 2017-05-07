// multiple inheritance
#include <iostream>
using namespace std;

class Polygon {
protected:
	int width, height;
public:
	Polygon(int a, int b) : width(a), height(b) {}
};

class Output {
public:
	 void print(int i);
};

class Rectangle : public Polygon, public Output {
public:
	Rectangle(int a, int b) : Polygon(a, b) {}
	int area()
	{
		return width*height;
	}
};
void Output::print(int i)
{
	cout << "print" <<i<< endl;
}

class Triangle : public Polygon, public Output {
public:
	Triangle(int a, int b) : Polygon(a, b) {}
	int area()
	{
		return width*height / 2;
	}
};

int main() {
	Rectangle rect(4, 5);
	Triangle trgl(4, 5);
	rect.print(rect.area());
	trgl.print(trgl.area());
	return 0;
}