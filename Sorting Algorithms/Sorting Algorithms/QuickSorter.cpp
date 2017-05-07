/*
* Assignment #12: Compare sorting algorithms
*
* CMPE 180-92 Data Structures and Algorithms in C++
* Department of Computer Engineering
* R. Mak, Nov. 20, 2016
*/
#include "QuickSorter.h"
#include <utility>
#include <algorithm>
#include <iostream>
/**
* Default constructor.
*/
QuickSorter::QuickSorter() : VectorSorter() {}

/**
* Destructor.
*/
QuickSorter::~QuickSorter() {}

/**
* Run the quicksort algorithm.
* @throws an exception if an error occurred.
*/
void QuickSorter::run_sort_algorithm() throw (string)
{
	quicksort(0, size - 1);
}

/**
* The quicksort algorithm recursively sorts data subranges.
* @param left the left index of the subrange to sort.
* @param right the right index of the subrange to sort.
*/
void QuickSorter::quicksort(const int left, const int right)
{
	if (left >= right) return;

	int p = choose_pivot(left, right);
	int q = partition(left, right, p);

	quicksort(left, q - 1);
	quicksort(q + 1, right);

}

/**
* Choose the pivot according to a pivot strategy.
* The chosen pivot will be moved temporarily to the right end.
* @param left the left index of the partition to sort.
* @param right the right index of the partition to sort.
* @return the pivot value.
*/
int QuickSorter::choose_pivot(const int left, const int right)
{
	return choose_pivot_strategy(left, right);
}

/**
* Partition the subrange by moving data elements < pivot to the left
* and data elements > pivot to the right.
* @param left the left index of the partition to sort.
* @param right the right index of the partition to sort.
* @param pivot the pivot value.
*/
int QuickSorter::partition(const int left, const int right, const int pivot)
{
	//   http://codereview.stackexchange.com/questions/4582/sorting-algorithms-implemented-in-c
	int p = left;
	for (int i = p + 1; i <= right; ++i)
	{
		compare_count++;
		if (data[i] < data[p])
		{
			// swap(data, i, p);
			int tmp = data[i];
			data[i] = data[p];
			data[p] = tmp;
			move_count++;

			if (i != p + 1)
			{
				// swap(data, i, p+1);
				int tmp1 = data[i];
				data[i] = data[p + 1];
				data[p + 1] = tmp1;
				move_count++;
			}
			p = p + 1;
		}
	}

	return p;
}
