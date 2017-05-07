#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define SIZE 20

struct DataItem {
	int value;
	char* key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

hash(unsigned char *str)
{

	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	printf("%lu", hash);
	return hash;
}
struct DataItem *search(int key) {
	//get the hash 
	int hashIndex = hash(key);

	//move in array until an empty 
	while (hashArray[hashIndex] != NULL) {

		if (hashArray[hashIndex]->key == key)
			return hashArray[hashIndex];

		//go to next cell
		++hashIndex;

		//wrap around the table
		hashIndex %= SIZE;
	}

	return NULL;
}

void insert(char* key) {

	struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
	item->key = key;

	//get the hash 
	int hashIndex = hash(key);

	//move in array until an empty or deleted cell
	while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
		//go to next cell
		++hashIndex;

		//wrap around the table
		hashIndex %= SIZE;
	}

	hashArray[hashIndex] = item;
}

int main() {
	int m;
	int n;
	bool flag;
	scanf("%d %d", &m, &n);
	char* *magazine = malloc(sizeof(char*) * m);
	for (int magazine_i = 0; magazine_i < m; magazine_i++) {
		magazine[magazine_i] = (char *)malloc(10240 * sizeof(char));
		scanf("%s", magazine[magazine_i]);
	}
	char* *ransom = malloc(sizeof(char*) * n);
	for (int ransom_i = 0; ransom_i < n; ransom_i++) {
		ransom[ransom_i] = (char *)malloc(10240 * sizeof(char));
		scanf("%s", ransom[ransom_i]);
	}
	dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
	dummyItem->value = -1;
	dummyItem->key = "";
	for (int i = 0; i < m; i++)
	{

		insert(magazine[i]);
		puts("Im inserting");
	}
	for (int i = 0; i < n; i++)
	{
		 flag = false;
		item = search(ransom[i]);
		if (item == NULL)
		{
			flag = true;
			break;
		}
	}

	if (flag ==true) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}


	


	return 0;
}




