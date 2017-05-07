#include <iostream>
#include <iomanip>
#include "ChainedHT.h"

using namespace std;

/**
* Default constructor.
*/
ChainedHT::ChainedHT() : HashTable() {}

/**
* Constructor. Initialize each table slot to nullptr.
*/
ChainedHT::ChainedHT(int size) : HashTable(size)
{
	/***** Complete this member function. *****/
	HashNode *h2 = new HashNode();
	h2->entry = new HashEntry();
	//HashEntry *h3 = new HashEntry();
//	h2->entry = h3;
	table.assign(size, h2);


}

/**
* Destructor. Delete all the entries in the collision chains.
*/
ChainedHT::~ChainedHT()
{
	/***** Complete this member function. *****/
}

/**
* Search for a given table entry. Count the number of probes.
* @param key the key of the entry to find.
* @param probe_count the cumulative count of probes.
* @return a pointer to the entry if found, else return nullptr.
*/
HashEntry *ChainedHT::search(const string& word, int& probe_count)
{
	int index = hash(word);
	if (table[index]->entry->word == "")
	{
		return table[index]->entry;
	}
	else
	{
		while (table[index]->entry->word != "")
		{
			cout << word << "--------->" << index << endl;

			if (table[index]->entry->word == word)
			{
				probe_count++;
				return table[index]->entry;
			}
			else
			{
				cout << word << "--------->" << index << endl;

				probe_count++;
				if (table[index]->next->entry->word == "")
				{

					return nullptr;
					
				}
				table[index] = table[index]->next;
			}
			probe_count++;


			table[index] = table[index]->next;
		}
		return nullptr;
	}
	//probe_count++;	

	probe_count++;
	return nullptr;
}

/**
* If an entry isn't already in the table, enter it with a
* frequency count of 1. If the entry already exists,
* update it by incrementing its frequency count by 1.
* Count the number of probes from the initial search.
* @param key the key of the entry to enter or update.
* @return a pointer to the newly entered or updated entry.
*/
HashEntry *ChainedHT::enter(const string& word, int& probe_count)
{
	HashEntry *entry_ptr = search(word, probe_count);
	int index = hash(word);

	if (entry_ptr->word == "")
	{
		table[index] = new HashNode(new HashEntry(word));
	}
	else if (entry_ptr != nullptr && entry_ptr->word == word)
	{
		entry_ptr->count++;
	}
	else
	{
		probe_count++;
		HashNode *hn = table[index];
		while (hn->entry != nullptr)
		{
			probe_count++;
			if (hn->next == nullptr)
				break;
			hn = hn->next;
		}
		hn->next = new HashNode(new HashEntry(word));
		return hn->next->entry;
	}
	return entry_ptr;
}

/**
* Print the contents of the hash table.
* Skip empty table slots.
*/
void ChainedHT::dump() const
{
	/***** Complete this member function. *****/
}

/**
* Compute the average chain length.
*/
double ChainedHT::avg_chain_length() const
{
	/***** Complete this member function. *****/
	return 1.0;
}

