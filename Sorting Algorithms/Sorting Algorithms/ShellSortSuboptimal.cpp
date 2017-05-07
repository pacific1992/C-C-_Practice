/*
* Assignment #12: Compare sorting algorithms
*
* CMPE 180-92 Data Structures and Algorithms in C++
* Department of Computer Engineering
* R. Mak, Nov. 20, 2016
*/
#include "ShellSortSuboptimal.h"
#include<iostream>
/**
* Default constructor.
*/
ShellSortSuboptimal::ShellSortSuboptimal() {}

/**
* Destructor.
*/
ShellSortSuboptimal::~ShellSortSuboptimal() {}

/**
* Get the name of this sorting algorithm.
* @return the name.
*/
string ShellSortSuboptimal::name() const { return "Shellsort suboptimal"; }

/**
* Run the suboptimal shellsort algorithm.
* @throws an exception if an error occurred.
*/
void ShellSortSuboptimal::run_sort_algorithm() throw (string)
{
	///***** Complete this member function. *****/

	//http://www.sanfoundry.com/cplusplus-program-implement-shell-sort/

	int j;

	//Narrow the array by 2 everytime
	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		move_count++;

		for (int i = gap; i < size; ++i)
		{
			int temp = data[i];
			compare_count++;

			for (j = i; j >= gap && temp < data[j - gap]; j -= gap)
			{
				compare_count++;
				data[j] = data[j - gap];
				move_count++;
			}
			data[j] = temp;

		}
	}




}
