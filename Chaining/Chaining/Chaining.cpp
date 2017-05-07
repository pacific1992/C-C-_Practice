/*
* C++ Program to Implement Hash Tables chaining
* with Singly Linked Lists
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;
const int TABLE_SIZE = 128;

/*
* HashNode Class Declaration
*/
class HashNode
{
public:
	    int key;
	int value;
	HashNode* next;
	HashNode(int key, int value)
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}
};

/*
* HashMap Class Declaration
*/
class HashMap
{
private:
	HashNode** htable;
public:
	HashMap()
	{
		htable = new HashNode*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; i++)
			htable[i] = NULL;
	}
	~HashMap()
	{
		/*for (int i = 0; i < TABLE_SIZE; ++i)
		{
			HashNode* entry = htable[i];
			while (entry != NULL)
			{
				HashNode* prev = entry;
				entry = entry->next;
				delete prev;
			}
		}
		delete[] htable;*/
	}
	/*
	* Hash Function
	*/
	int HashFunc(int key)
	{
		return key % TABLE_SIZE;
	}

	/*
	* Insert Element at a key
	*/
	void Insert(int key, int value)
	{
		int hash_val = HashFunc(key);
		HashNode* prev = NULL;
		HashNode* entry = htable[hash_val];
		while (entry != NULL)
		{
			prev = entry;
			entry = entry->next;
		}
		if (entry == NULL)
		{
			entry = new HashNode(key, value);
			if (prev == NULL)
			{
				htable[hash_val] = entry;
			}
			else
			{
				prev->next = entry;
			}
		}
		else
		{
			entry->value = value;
		}
	}
};
/*
* Main Contains Menu
*/
int main()
{
	HashMap hash;
	int key, value;
	int choice;
	while (1)
	{
		cout << "\n----------------------" << endl;
		cout << "Operations on Hash Table" << endl;
		cout << "\n----------------------" << endl;
		cout << "1.Insert element into the table" << endl;
		cout << "4.Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter element to be inserted: ";
			cin >> value;
			cout << "Enter key at which element to be inserted: ";
			cin >> key;
			hash.Insert(key, value);
			break;
		default:
			cout << "\nEnter correct option\n";
		}
	}
	return 0;
}