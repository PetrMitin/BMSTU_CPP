#include <stdio.h>
#include <cstdlib>
using namespace std;

void printStarts(int n, int counter)
{
	for (int i = 1; i <= n - abs(n - counter); i++) printf("*");
	printf("\n");
	if (2 * n >= counter) printStarts(n, counter + 1);
}

int main()
{
	int n;
	scanf_s("%i", &n);
	printStarts(n, 1);
	return 0;
}