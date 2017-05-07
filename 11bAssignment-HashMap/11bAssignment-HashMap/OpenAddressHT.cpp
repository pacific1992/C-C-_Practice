#include <iostream>
#include <iomanip>
#include "OpenAddressHT.h"
#include "HashEntry.h"

using namespace std;

/**
* Default constructor
*/
OpenAddressHT::OpenAddressHT() : HashTable() {}

/**
* Constructor. Initialize each table slot to nullptr.
*/
OpenAddressHT::OpenAddressHT(int size) : HashTable(size)
{
	HashEntry *h2 = new HashEntry();

	table.assign(size, h2);

	/***** Complete this member function. *****/
}

/**
* Destructor. Delete all the entries in the table.
*/
OpenAddressHT::~OpenAddressHT()
{
	/***** Complete this member function. *****/

}

/**
* Return an entry at a given index of the hash table.
* @param index the index.
* @return the entry.
*/
HashEntry *OpenAddressHT::get_entry(const int index) const
{
	/***** Complete this member function. *****/

	//cout << "Hey" << endl;

	return table[index];
}

/**
* Search for a given table entry. Count the number of probes.
* @param key the key of the entry to find.
* @param probe_count the cumulative count of probes.
* @return the hash table index of the entry if found, else of an empty slot.
*/
int OpenAddressHT::search(const string& key, int& probe_count)
{
	/***** Complete this member function. *****/
	

	int index = hash(key);


	
	//	cout << key << "----else----->" << index << endl;

		while (index< table.size())
		{
			//cout << key << "--------->" << index << endl;

			if (table[index]->word == "" || table[index]->word == key)
			{
					probe_count++;
					return index;
			}

			index = next_index(index);
			probe_count++;
			if (index >= table.size())
			{
				index = 0;
			}
		}
	//}

}

/**
* If an entry isn't already in the table, enter it with a
* frequency count of 1. If the entry already exists,
* update it by incrementing its frequency count by 1.
* Count the number of probes from the initial search.
* @param key the key of the entry to enter or update.
* @return the index of the newly entered or updated entry.
*/
int OpenAddressHT::enter(const string& key, int& probe_count)
{
	//cout << "ENter common enter" << endl;

	//cout << "table size-->" << get_size()<<endl;

	// Search for the entry key.
		int index = search(key, probe_count);
	//	HashEntry* h2 = new HashEntry;

		HashEntry* h = new HashEntry(key);
		
		if (table[index]->word == "")
		{
//			cout << key << "---in-->" << index << endl;

			table[index] = h;
		}
		else
		{
		//	cout << "index2 -->" << index << endl;
			table[index]->count++;
		//	cout << key << "-->" << index<<"--->"<< table[index]->count<< endl;
		}
		
//		cout << "table 23-->" << table[23]->word << endl;
	/*	if (key == "electors")
		{
			cout << key << "-->" << index << endl;

		}*/
 

	return index;
}

/**
* Print the contents of the hash table.
* Skip empty table slots.
*/
void OpenAddressHT::dump() const
{
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i]->word != "")
		{
			cout <<i<<":     "<< table[i]->count << "-" << table[i]->word << endl;
		}
	}
	/***** Complete this member function. *****/
}
