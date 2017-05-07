/*
* Assignment #12: Compare sorting algorithms
*
* CMPE 180-92 Data Structures and Algorithms in C++
* Department of Computer Engineering
* R. Mak, Nov. 20, 2016
*/
#include "ShellSortOptimal.h"

/**
* Default constructor.
*/
ShellSortOptimal::ShellSortOptimal() {}

/**
* Destructor.
*/
ShellSortOptimal::~ShellSortOptimal() {}

/**
* Get the name of this sorting algorithm.
* @return the name.
*/
string ShellSortOptimal::name() const { return "Shellsort optimal"; }

/**
* Run the optimal shellsort algorithm.
* According to Don Knuth:
* h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
* @throws an exception if an error occurred.
*/
void ShellSortOptimal::run_sort_algorithm() throw (string)
{
	/***** Complete this member function. *****/
	//http://stackoverflow.com/questions/4833423/shell-sort-java-example
	int inner, outer;
	long temp;
	//find initial value of h
	int h = 1;
	while (h <= size / 3)
		h = h * 3 + 1; // (1, 4, 13, 40, 121, ...)

	while (h > 0) // decreasing h, until h=1
	{
		// h-sort the file
		for (outer = h; outer < size; outer++)
		{
			temp = data[outer];
			inner = outer;
			// one subpass (eg 0, 4, 8)
			while (inner > h - 1 && data[inner - h] >= temp) {
				compare_count++;
				data[inner] = data[inner - h];
				move_count++;
				inner -= h;
			}
			data[inner] = temp;
			move_count++;
		}
		h = (h - 1) / 3; // decrease h
	}
}













	