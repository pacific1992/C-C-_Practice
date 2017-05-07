#include <stdio.h>
#include "Header.h"
#include "stdint.h"


	  extern int p;

unsigned int Bits_swap(unsigned int z)
{

	// Get all even bits of z.
	// The numbhttps://try.github.io/levels/1/challenges/3er 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0.
	unsigned int even_bits = z & 0xA;
	// Get all odd bits of z
	// The number 0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 0.
	unsigned int odd_bits = z & 0x5;

	even_bits =even_bits>> 1;  // Right shift even bits
	odd_bits <<= 1;   // Left shift odd bits

	return (even_bits | odd_bits); // Combine even and odd bits
}

void sayHello() {       
	printf("hello world");
}  
// Driver program to test above function
int main()
{


	uint8_t x = 9; // 00111000
	//p++;				 // Output is 52 (00110100)
	//printf("%d ", p);
	void(*sayHelloPtr)() = sayHello; //Line 6 
	(*sayHelloPtr)();       //Line 7

	return 0;
}