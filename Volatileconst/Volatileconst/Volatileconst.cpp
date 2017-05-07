// Volatileconst.cpp : Defines the entry point for the console application.
//

#include<iostream>

int main()
{
	const volatile int c = 10;
	c++;// bad
    return 0;
}

