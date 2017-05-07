/* Function to get no of set bits in binary
representation of passed binary no. */

#include<iostream>
#include<stdint.h>
using namespace std;
unsigned int countSetBits(uint32_t  n)
{
	// Java: use >>> instead of >>
	// C or C++: use uint32_t
	n = n - ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	return (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int bitCount(unsigned int n) {
		int counter = 0;
		while (n != 0)
		{
			counter++;
			n = n & (n-1);
		//	n = n >> 1;
		}
		return counter;
	}

/* Program to test function countSetBits */
int main()
{
	int i = 9;
	//printf("%d\n", countSetBits(i));
//	getchar();
	int x = bitCount(16);
	cout <<"ans-->"<< x << endl;
	return 0;
}