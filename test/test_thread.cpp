#include <iostream>
#include <thread>
#include <vector>

#include "getcputime.h"
#include "gf_default_table.h"

#define TYPE_DEFAULT 1
#define TYPE_SPLIT 2
#define TYPE_COMPOSITE 3

void func1(void)
{
	std::cout << "Im func1\n";
}

void usage(char *s)
{
	std::cout << "@ARG1 must be: " << "\n";
	std::cout << "    default: gf_default_table();" << "\n";
	std::cout << "    split:   gf_split_table();" << "\n";
	std::cout << "    composite:   gf_composite();" << "\n";
	std::cout << "@ARG2:         " << "Number of threads" << "\n";
}

int main(int argc, char *argv[])
{
	if(argc != 3) usage(NULL);

	char *arg = argv[1];
	std::string opt = std::string(arg);

	int scase = 0;
	if(opt == "default")
		scase = TYPE_DEFAULT;
	else if(opt == "split")
		scase = TYPE_SPLIT;
	else if(opt == "composite")
		scase = TYPE_COMPOSITE;
	else
		scase = TYPE_DEFAULT;

	int (*func_stub)(void);

	double start = 0.0;
	double end = 0.0;

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

	start = getCPUTime();
	int threadNum = atoi(argv[2]);
	std::vector<std::thread> threads;
	for(int i = 0; i < threadNum; ++i)
		threads.push_back(std::thread(func_stub));

	for(int i = 0; i < threadNum; ++i)
		threads[i].join();
	end = getCPUTime();
	std::cout << "Total Time of Threads: " << end-start << "\n";
	return 0;
}