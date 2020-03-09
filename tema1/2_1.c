#include <stdio.h>

int main(void) 
{
	for (int i = 1; i < 30; i++) printf("%1d", i % 10);
	printf("\n%13s%6s", "Curmanschii", "Anton");
	printf("\n%-8.1f%-6.1f%-5.1f", 22.3, 16.8, 22.3);
	printf("\n%-11.1f%-8.2f", 15.8, 0.15);
	printf("\n%10.1f%8.1f", 62.3, 16.8);
	printf("\n%-6s%s", "***", "***");
	printf("\n%6s%7.1f", "***", 15.8);
	printf("\n%-11s%s", "Miracol", "USM");
	printf("\n%11.1f", 14.5);
	printf("\n%-15.1f%4.1f", 22.3, 22.3);
	printf("\n%9.1f", 15.8);
	printf("\n%13.1f", 16.9);
	printf("\n%-12.1f%4.1f", 17.8, 16.3);
	printf("\n%8.1f", 15.2);
	printf("\n%9d%5d%4d", 22, 13, 14);
	printf("\n%-8d%-6.1f%4.1f", 15, 22.3, 15.3);
	printf("\n%5d", 16);
	return 0;
}