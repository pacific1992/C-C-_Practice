/*
* Assignment #12: Compare sorting algorithms
*
* CMPE 180-92 Data Structures and Algorithms in C++
* Department of Computer Engineering
* R. Mak, Nov. 20, 2016
*/
#include "InsertionSort.h"

/**
* Default constructor.
*/
InsertionSort::InsertionSort() : VectorSorter() {}

/**
* Destructor.
*/
InsertionSort::~InsertionSort() {}

/**
* Get the name of this sorting algorithm.
* @return the name.
*/
string InsertionSort::name() const { return "Insertion sort"; }

/**
* Run the insertion sort algorithm.
* @throws an exception if an error occurred.
*/
void InsertionSort::run_sort_algorithm() throw (string)
{
	/***** Complete this member function. *****/
	//http://mycodinglab.com/insertion-sort-algorithm/


	int i, j, tmp;
	compare_count++;
	for (i = 1; i < size; i++)
	{
		j = i;
		compare_count++;
		while (j > 0 && data[j - 1] > data[j])
		{
			swap(j, j - 1);
			j--;
		}//end of while loop
	}//end of for loop


}
