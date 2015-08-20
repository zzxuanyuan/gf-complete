#include <stdio.h>
//#include <thread>
//#include <vector>
#include <pthread.h>
#include <stdlib.h>

#include "gf_default_table.h"

#define TYPE_DEFAULT 1
#define TYPE_SPLIT 2
#define TYPE_COMPOSITE 3

void func1(void)
{
	fprintf(stdout, "Im func1\n");
}

void usage(char *s)
{
	fprintf(stdout, "@ARG1 must be: \n");
	fprintf(stdout, "    default: gf_default_table();\n");
	fprintf(stdout, "    split:   gf_split_table();\n");
	fprintf(stdout, "    composite:   gf_composite();\n");
	fprintf(stdout, "@ARG2:         Number of threads\n");
}

int main(int argc, char *argv[])
{
	if(argc != 3) {usage(NULL);exit(1);}

	int scase = 0;
	if(!strncmp(argv[1], "default", 7))
		scase = TYPE_DEFAULT;
	else if(!strncmp(argv[1], "split", 5))
		scase = TYPE_SPLIT;
	else if(!strncmp(argv[1], "composite", 9))
		scase = TYPE_COMPOSITE;
	else
		scase = TYPE_DEFAULT;
	fprintf(stdout, "test1\n");
	double start = 0.0;
	double end = 0.0;

	void *(*func_stub)(void *arg) = NULL;

	switch(scase)
	{
		case 1:
		{
			func_stub = gf_default_table;
			break;
		}
		case 2:
		{
			func_stub = gf_split_table;
			break;
		}
		case 3:
		{
			func_stub = gf_composite;
			break;
		}
		default:
		{
			func_stub = gf_default_table;
			break;
		}
	}
	if(func_stub == NULL)
		fprintf(stdout, "func_stub is NULL\n");
	else
		fprintf(stdout, "scase: %d\n", scase);
/*
	start = getCPUTime();
	int threadNum = atoi(argv[2]);
	std::vector<std::thread> threads;
	for(int i = 0; i < threadNum; ++i)
		threads.push_back(std::thread(func_stub));

	for(int i = 0; i < threadNum; ++i)
		threads[i].join();
	end = getCPUTime();
*/
	fprintf(stdout, "test2\n");
	start = getCPUTime();
	int threadNum = atoi(argv[2]);
	pthread_t threads[threadNum];
	int i;
	for(i = 0; i < threadNum; ++i){
		if(pthread_create(&threads[i], NULL, func_stub, NULL)){
			fprintf(stdout, "Error Creating\n");
			return 1;
		}
	}
	fprintf(stdout, "test3\n");
	for(i = 0; i < threadNum; ++i) {
		if(pthread_join(threads[i], NULL)){
			fprintf(stdout, "Error Joining\n");
			return 1;
		}
	}
	fprintf(stdout, "test4\n");
	end = getCPUTime();
	fprintf(stdout, "test5\n");
	fprintf(stdout, "Total Time of Threads: %f\n", end-start);
	return 0;
}
