// BitManip.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdint.h>
using namespace std;
uint8_t swap_nibble(uint8_t num)
{
	uint8_t high_nibble = (num >> 4);
	//printf("%d\n", high_nibble);
		uint8_t low_nibble = num;
	return (low_nibble << 4) | (high_nibble);
}
int bitsInsert(int x, int y, int a, int b)
{
	int allOnes = ~0;
	int left = allOnes << (b + 1);
	int right = (1 << a) - 1;
	int num = left | right;
	x = x & num;
	y = y << a;
	return x | y;
}
int bitCount(unsigned int n) {

	int counter = 0;
	while (n) {
		counter++;
		n >>= 1;
	}
	return counter;
}
int bitSwapConversion(int x, int y)
{
	int count = 0;
	int n = x^y;
	while (n != 0)
	{
		count++;
		n >>= 1;
	}
	return count;
}
int nextGreater(int x)
{
	int count = 0;;
	int y = x;
	while (y != 0)
	{
		count += y & (1 << 0);
		y = y >> 1;
		
	}
//	cout << count;
	int c = 0;
	for (int i = 1;; i++)
	{
		y = x + i;
//		cout << y << endl;
		while (y != 0)
		{

			c += y & (1 << 0);
			y = y >> 1;
	//		cout << count<<endl;
		}
		if (c == count)
		{
			//	cout << y << endl;

			y = x + i;
			break;
		}
		if (c == count)
		{
			break;
		}
		c = 0;
	}
	return y;
}

uint8_t swap_evenodd(uint8_t num)
{
	uint8_t even =num & 0x55;
//	printf("%d\n", even);

	uint8_t odd = num & 0xAA;
//	printf("%d\n", odd);

	even <<= 1;
	odd >>= 1;
	return (odd) | (even);
}

int main()
{
	int n = 0;
	while (n & (1 << 0)==0)
	{
		cin >> n;
		cout << "hey" << endl;

	}
	uint8_t i = swap_nibble(1);
	uint8_t i2 = swap_evenodd(1);
	int x = bitSwapConversion(2, 3);
	//cout << x;
	//int y = bitCount(1);
	//int y = bitSwapConversion(7,8);
	int y = nextGreater(3);
	cout << y;

//	cout << "Bit 0 is set now" << endl;
	//printf("%d\n", i);
//	printf("%d\n", i2);

    return 0;
}

