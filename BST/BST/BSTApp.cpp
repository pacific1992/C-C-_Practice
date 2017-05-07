#include <iostream>

#include <vector>

#include <ctime>

#include <time.h>

#include <chrono>



using namespace std::chrono;



#include "BinarySearchTree.h"

#include "AvlTree.h"

#include "BinaryTreeChecker.h"

#include "BinaryTreePrinter.h"



using namespace std;



const bool DUMP = false;



void testBST();

void testAVL();



void makeTree(BinarySearchTree<int>& tree,

	BinaryTreeChecker<int>& checker,

	BinaryTreePrinter<int>& printer,

	string kind);



void testTree(BinarySearchTree<int>& tree,

	BinaryTreeChecker<int>& checker,

	BinaryTreePrinter<int>& printer);



/**

* Main.

*/

int VALUES[100000];

int s1[10000];

int s2[20000];

int s3[30000];

int s4[40000];

int s5[50000];

int s6[60000];

int s7[70000];

int s8[80000];

int s9[90000];

int s10[100000];

int main()

{

	int r;

	for (int i = 0; i<100000; i++)

	{

		r = (rand() % 100000) + 1;

		VALUES[i] = r;

	}

	for (int i = 0; i<10000; i++)

	{

		r = (rand() % 10000) + 1;

		s1[i] = r;

	}

	for (int i = 0; i<20000; i++)

	{

		r = (rand() % 20000) + 1;

		s2[i] = r;

	}

	for (int i = 0; i<30000; i++)

	{

		r = (rand() % 30000) + 1;

		s3[i] = r;

	}

	for (int i = 0; i<40000; i++)

	{

		r = (rand() % 40000) + 1;

		s4[i] = r;

	}

	for (int i = 0; i<50000; i++)

	{

		r = (rand() % 50000) + 1;

		s5[i] = r;

	}

	for (int i = 0; i<60000; i++)

	{

		r = (rand() % 60000) + 1;

		s6[i] = r;

	}

	for (int i = 0; i<70000; i++)

	{

		r = (rand() % 70000) + 1;

		s7[i] = r;

	}

	for (int i = 0; i<80000; i++)

	{

		r = (rand() % 80000) + 1;

		s8[i] = r;

	}

	for (int i = 0; i<90000; i++)

	{

		r = (rand() % 90000) + 1;

		s9[i] = r;

	}

	for (int i = 0; i<100000; i++)

	{

		r = (rand() % 100000) + 1;

		s10[i] = r;

	}



	testBST();

	testAVL();

}



/**

* Run the test with a binary search tree.

*/

void testBST()

{

	cout << endl;

	cout << "**********************" << endl;

	cout << "* BINARY SEARCH TREE *" << endl;

	cout << "**********************" << endl;



	BinarySearchTree<int>  tree;

	BinaryTreeChecker<int> checker(tree);

	BinaryTreePrinter<int> printer(tree);

	makeTree(tree, checker, printer, "BST");

	//testTree(tree, checker, printer);

}



/**

* Run the test with an AVL tree.

*/

void testAVL()

{

	cout << endl;

	cout << "************" << endl;

	cout << "* AVL TREE *" << endl;

	cout << "************" << endl;



	AvlTree<int> tree;

	BinaryTreeChecker<int> checker(tree);

	BinaryTreePrinter<int> printer(tree);

	makeTree(tree, checker, printer, "AVL");

	//testTree(tree, checker, printer);

}



// static const int VALUES[] = {

//     62,71,29,88,11,41,21,66,57,27,39,40,77,20,51,49,82,37,

//     94,63,76,91,70,64,60,90,12,80,23,10,52,35,96,75,28

// };



//static const int VALUES[]={10000,20000,30000,40000,50000,60000,70000,80000,90000,100000};



/**

* Make a binary search tree containing unique random integer data items.

* @param tree the tree to make.

* @param maxNodes the maximum number of nodes to generate.

* @param checker the binary tree checker to use.

* @param printer the binary tree printer to use.

* @param insertPrint true iff print a message after each node insertion

*/

void makeTree(BinarySearchTree<int>& tree,

	BinaryTreeChecker<int>& checker,

	BinaryTreePrinter<int>& printer,

	string kind)

{

	srand(time(NULL));

	int r;

	long search_time;

	steady_clock::time_point start_time = steady_clock::now();

	for (int n = 0; n<100000; n++)

	{

		cout << endl << "Inserted node " << VALUES[n] << ":" << endl;

		tree.insert(VALUES[n]);  // insert into tree

		checker.add(VALUES[n]);  // store with the tree checker

		cout << endl;

		//printer.print();

	}

	steady_clock::time_point end_time = steady_clock::now();

	long elapsed_time = duration_cast<milliseconds>(end_time - start_time).count();

	cout << elapsed_time << endl;

	start_time = steady_clock::now();

	for (int x : s1)

	{

		bool y = tree.contains(x);

		//cout<<x<<" - "<<y<<endl;

	}

	end_time = steady_clock::now();

	search_time = duration_cast<milliseconds>(end_time - start_time).count();

	cout << search_time << "  for " << s1 << endl;



	start_time = steady_clock::now();

	for (int x : s2)

	{

		bool y = tree.contains(x);

	}

	end_time = steady_clock::now();

	search_time = duration_cast<milliseconds>(end_time - start_time).count();

	cout << search_time << "  for " << s2 << endl;



	start_time = steady_clock::now();

	for (int x : s3)

	{

		bool y = tree.contains(x);

	}

	end_time = steady_clock::now();

	search_time = duration_cast<milliseconds>(end_time - start_time).count();

	cout << search_time << "  for " << s3 << endl;



	start_time = steady_clock::now();

	for (int x : s4)

	{

		bool y = tree.contains(x);

	}

	end_time = steady_clock::now();

	search_time = duration_cast<milliseconds>(end_time - start_time).count();

	cout << search_time << "  for " << s4 << endl;



	start_time = steady_clock::now();

	for (int x : s5)

	{

		bool y = tree.contains(x);

	}

	end_time = steady_clock::now();

	search_time = duration_cast<milliseconds>(end_time - start_time).count();

	cout << search_time << "  for " << s5 << endl;



	start_time = steady_clock::now();

	for (int x : s6)

	{

		bool y = tree.contains(x);

	}

	end_time = steady_clock::now();

	search_time = duration_cast<milliseconds>(end_time - start_time).count();

	cout << search_time << "  for " << s6 << endl;



	start_time = steady_clock::now();

	for (int x : s7)

	{

		bool y = tree.contains(x);

	}

	end_time = steady_clock::now();

	search_time = duration_cast<milliseconds>(end_time - start_time).count();

	cout << search_time << "  for " << s7 << endl;



	start_time = steady_clock::now();

	for (int x : s8)

	{

		bool y = tree.contains(x);

	}

	end_time = steady_clock::now();

	search_time = duration_cast<milliseconds>(end_time - start_time).count();

	cout << search_time << "  for " << s8 << endl;



	start_time = steady_clock::now();

	for (int x : s9)

	{

		bool y = tree.contains(x);

	}

	end_time = steady_clock::now();

	search_time = duration_cast<milliseconds>(end_time - start_time).count();

	cout << search_time << "  for " << s9 << endl;



	start_time = steady_clock::now();

	for (int x : s10)

	{

		bool y = tree.contains(x);

	}

	end_time = steady_clock::now();

	search_time = duration_cast<milliseconds>(end_time - start_time).count();

	cout << search_time << "  for " << s10 << endl;

	cout << endl;

	cout << "*****" << endl;

	cout << "***** COMPLETED " << kind << " TREE:" << endl;

	cout << "*****" << endl << endl;

	//printer.print();

}



/**

* Test a binary tree.

* @param tree the tree to test.

* @param checker the binary tree checker to use.

* @param printer the binary tree printer to use.

*/

void testTree(BinarySearchTree<int>& tree,

	BinaryTreeChecker<int>& checker,

	BinaryTreePrinter<int>& printer)

{

	int status = BinaryTreeChecker<int>::NO_ERROR;



	// Delete the root node each time through the loop.

	// Print the tree after each deletion.

	while (!tree.isEmpty())

	{

		BinaryNode<int> *root = tree.getRoot();

		int data = root->data;

		cout << endl << "Deleted root node " << data << ":" << endl;



		tree.remove(data);

		checker.remove(data);



		cout << endl;

		//printer.print();



		status = checker.check(DUMP);

		if (status != BinaryTreeChecker<int>::NO_ERROR) break;

	}



	// What was the status?

	string msg;

	switch (status)

	{

	case BinaryTreeChecker<int>::NO_ERROR:

	{

		msg = ">>>>> The tree is now empty.";

		break;

	}

	case BinaryTreeChecker<int>::DATA_MISMATCH:

	{

		msg = ">>>>> Data mismatch.";

		break;

	}

	case BinaryTreeChecker<int>::INSUFFICIENT_DATA:

	{

		msg = ">>>>> Data missing from tree.";

		break;

	}

	case BinaryTreeChecker<int>::REMAINING_DATA:

	{

		msg = ">>>>> Data remaining in tree.";

		break;

	}

	}

	cout << msg << endl;

}