#include "getcputime.h"

double getCPUTime(void)
{
	double thetime = 0.0;
	struct timespec currtime;
	int ret;
	ret = clock_gettime(CLOCK_REALTIME, &currtime);
	if(ret < 0)
		fprintf(stderr, "clock_gettime error\n");
	thetime = (currtime.tv_sec*1000000000+currtime.tv_nsec)/1000000.0;
	return thetime;
}

