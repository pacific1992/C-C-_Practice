#include <stdio.h>
#include "Header.h"
#include "stdint.h"

 int p;

unsigned int Bits(unsigned int z)
{
	// Get all even bits of z.
	// The number 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0.
	unsigned int even_bits = z & 0xA;

	// Get all odd bits of z
	// The number 0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 0.
	unsigned int odd_bits = z & 0x5;

	even_bits = even_bits >> 1;  // Right shift even bits
	odd_bits <<= 1;   // Left shift odd bits

	return (even_bits | odd_bits); // Combine even and odd bits
}

