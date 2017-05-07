#include<iostream>
#include<string>

typedef struct movies_t {
	char* title;
	int year;
}Movie;

int main()
{

	Movie amovie;
	printf("%X\n", &amovie);
	movies_t *pmovie = &amovie;
	amovie.title = "Yay";
	amovie.year = 200;
	printf("%X\n", &pmovie);
	printf("%X\n", pmovie);
printf("%d\n", sizeof(pmovie));
printf("%d\n", sizeof(pmovie->title));
printf("%d\n", sizeof(pmovie->year));



	return 0;
}
