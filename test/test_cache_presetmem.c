#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef	B20M
#define B20M 20*1024*1024
#endif

int main()
{
	char ch;
	char *mem = (char *)malloc(B20M);
	memset(mem, 0, B20M);
	int i;
	for(i = 0; i < B20M; ++i)
	{
		ch = mem[i];
	}
	free(mem);
	return 0;
}