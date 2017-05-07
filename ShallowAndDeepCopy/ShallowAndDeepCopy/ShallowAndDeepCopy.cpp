// ShallowAndDeepCopy.cpp : Defines the entry point for the console application.
//

#include <iostream>

int main()
{
	int *f, *s;
	f = new int[10];
	for (int i = 0; i < 10; i++)
	{
		f[i] = 10;
	}
	s = f; //shallow copy
//	printf("%d\n", f[0]);
	printf("s-->%X\n", s);
	printf("f-->%X\n", f);

	delete []s;
//	printf("%d\n", f[0]);// dangling pointers
	printf("s-->%X\n", s);
	int *f2, *s2;
	for (int i = 0; i < 10; i++)
	{
		f[i] = 10;
	}
	s2 = new int[10];
	f2 = new int[10];
	printf("s2-->%X\n", s2);
	printf("f2-->%X\n", f2);

	for (int i = 0; i < 10; i++)
	{
		f2[i] = 10;
	}
	for (int i = 0; i < 10; i++)
	{
		s2[i] = f2[i]; //deep copy
	}

	delete []s2;
	printf("%d\n", f2[0]);// dangling pointers


	return 0;
}

