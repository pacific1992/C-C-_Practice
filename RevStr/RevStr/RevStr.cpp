#include<iostream>
#include<string>
using namespace std;

void reverseChar(char* str);
string revStr(string s);

char str[50], rstr[50];
int i, n;

int main()
{
	cout << "Please Enter the String: ";
	cin.getline(str, 50);
	reverseChar(str);
	cout << rstr;
	string t;
	string s = "Jelo";
	t = revStr(s);
	cout << t;
	return 0;
}

void reverseChar(char* str)
{
	int j = 0;
	for (i = strlen(str)-1; i>=0; i--)
	{
		rstr[j]=str[i];
		j++;
	}
}
string revStr(string s)
{
	reverse(s.begin,s.end);
	return s;
}