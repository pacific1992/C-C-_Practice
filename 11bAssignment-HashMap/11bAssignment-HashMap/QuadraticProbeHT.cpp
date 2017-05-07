#include "QuadraticProbeHT.h"
#include <iostream>

using namespace std;

QuadraticProbeHT::QuadraticProbeHT() : OpenAddressHT(), odd(1) {
	//cout << "Qcon table size1-->" << get_size() << endl;

}
QuadraticProbeHT::QuadraticProbeHT(int size) : OpenAddressHT(size), odd(1) {
	//c//out << "Qcon table size-->" << get_size() << endl;
}

QuadraticProbeHT::~QuadraticProbeHT() {}

/**
* Search for a given table entry. Overrides OpenAddressHT::search().
* @param key the key of the entry to find.
* @param probe_count the cumulative count of probes.0
* @return the hash table index of the entry if found, else of an empty slot.
*/
int QuadraticProbeHT::search(const string& key, int& probe_count)
{
	odd = 1;
	int index = hash(key);
	int next_empty_slot = 0;
	int flag = 0;

	/*if (key == "subsequent" || key=="right")
	{
		cout << key << "----first----->" << index << endl;
	}
*/
	
		//cout << key << "----else----->" << index << endl;
		while (index< get_size())
		{
			//		if (key == "cases" || key == "right")
			//			cout << key << "----if----->" << index << endl;
			if (get_entry(index)->word == "" || get_entry(index)->word == key)
			{
		//		if (key == "subsequent" || key == "right")
			//		cout << key << "----if----->" << index << endl;
				probe_count++;

				return index;
			}
		
//			cout << key << "------bf--->" << index << endl;

			index = next_index(index);
			probe_count++;

	//	cout << key << "------af--->" << index << endl;

		
	//		if (key == "cases" || key == "right")
	//			cout << key << "------out--->" << index << endl;

		//	if (key == "intervened")
			//	cout << "size-->" << get_size() << endl;
			if (index >= get_size())
			{
				probe_count++;

				index = 0;
			}
		}
	//}
}

/**
* Compute the index of the next hash table slot away from
* the current slot to check. For quadratic probing, the ith probe
* checks the slot that is i-squared away from the home slot
* computed by hash(). Use the formula n^2 = 1 + 3 + 5 + ... + 2n-1.
* Use private member variable odd to compute the successive squares.
* @param index the index of the current slot.
* @return the index of the next slot.
*/
int QuadraticProbeHT::next_index(int index)
{
	int i = 1;
	while (i <= odd)
	{
		index =index + i;
		i = i + 2;

	}
	odd++;
	odd++;
//	cout << "Odd-->" << odd << endl;
	return index;
}