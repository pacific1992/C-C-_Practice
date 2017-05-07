#include <iostream>

using namespace std;

void test_standard_predefined_macros();

int main()
{
	test_standard_predefined_macros();

	return 0;
}
//Macro is fragment of code which is give a name
void test_standard_predefined_macros()
{
	cout << "File: " << __FILE__ << endl;
	cout << "Function: " << __func__ << endl;
	cout << "Line: " << __LINE__ << endl;
	cout << "Time: " << __TIME__ << endl;
	cout << "Date: " << __DATE__ << endl;

}

