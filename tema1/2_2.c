#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(void) 
{
	for (int i = 1; i < 30; i++) printf("%1d", i % 10);

	printf("\n%7s%-6s", "Hello", "World");
	printf("\n%11s", "Utility");
	printf("\n\n%10s", "Programs");
	printf("\n\n%-4d%-4d%-4d%-4d", 123, 123, 123, 123);
	printf("\n\n%-4d%-8d%-4d", 321, 321, 321);
	

	_getch();
	return 0;
}