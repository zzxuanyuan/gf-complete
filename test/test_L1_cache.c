#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getcputime.h"

#ifndef B32K	// L1 cache on my desktop
#define B32K 32*1024
#endif
#ifndef B256K	//L2 cache on my desktop
#define B256K 256*1024
#endif
#ifndef B6M	//L3 cache on my desktop
#define B6M 6*1024*1024
#endif
#ifndef B20M	// Larger than L3 cache on my desktop
#define B20M 20*1024*1024
#endif
#ifndef B1G	// Very large memory
#define B1G 1024*1024*1024
#endif

void test_B16(char *mem)
{
	printf("test_B16\n");
	char ch;
	int i;
	for(i = 0; i < 16; ++i)
	{
		mem[i] = 'a';
	}
}

void test_B32K(char *mem)
{
	printf("test_B32K\n");
	char ch;
	int i;
	for(i = 0; i < B32K; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B32K; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B32K; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B32K; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B32K; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B32K; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B32K; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B32K; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B32K; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B32K; ++i)
	{
		mem[i] = ch + 10;
	}	
}

void test_B256K(char *mem)
{
	printf("test_B256K\n");
	char ch;
	int i;
	for(i = 0; i < B256K; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B256K; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B256K; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B256K; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B256K; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B256K; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B256K; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B256K; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B256K; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B256K; ++i)
	{
		mem[i] = ch + 10;
	}	
}

void test_B6M(char *mem)
{
	printf("test_B6M\n");
	char ch;
	int i;
	for(i = 0; i < B6M; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B6M; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B6M; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B6M; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B6M; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B6M; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B6M; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B6M; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B6M; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B6M; ++i)
	{
		mem[i] = ch + 10;
	}	
}

void test_B20M(char *mem)
{
	printf("test_B20M\n");
	char ch;
	int i;
	for(i = 0; i < B20M; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B20M; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B20M; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B20M; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B20M; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B20M; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B20M; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B20M; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B20M; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B20M; ++i)
	{
		mem[i] = ch + 10;
	}	
}

void test_B1G(char *mem)
{
	printf("test_B1G\n");
	char ch;
	int i;
	for(i = 0; i < B1G; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B1G; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B1G; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B1G; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B1G; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B1G; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B1G; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B1G; ++i)
	{
		mem[i] = ch + 10;
	}
	for(i = 0; i < B1G; ++i)
	{
		ch = mem[i];
	}
	for(i = 0; i < B1G; ++i)
	{
		mem[i] = ch + 10;
	}	
}

int main()
{
	double start = 0.0;
	double end = 0.0;
	char *mem = (char *)malloc(B1G);
	bzero(mem, B1G);
	start = getCPUTime();
	printf("this is test_L1_cache\n");
//	test_B16(mem);
//	test_B32K(mem);
//	test_B256K(mem);
//	test_B6M(mem);
	test_B20M(mem);
//	test_B1G(mem);
	end = getCPUTime();
	printf("Time: %f (ms)", end-start);
	free(mem);
	return 0;
}