#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "clean_cache.h"

int main(int argc, char *argv[])
{
	char *mem = (char *)malloc(B1G);
	bzero(mem, B1G);
	char tinybyte;
	unsigned long addr = 0;
	printf("long: %lu\n", addr-1);
	int i;
	for(i = 0; i < B1G; ++i)
	{
		addr = rand()%B1G;
		tinybyte = mem[i];
	}
	return 0;
}