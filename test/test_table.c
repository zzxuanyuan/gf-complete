#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getcputime.h"
#include "ec_base.h"

#define CHUNKSIZE 64

void dump(unsigned char *mem, int size)
{
	fprintf(stdout, "dump:\n");
	int i = 0;
	fprintf(stdout, " %2x", 0xff & mem[i]);
	for(i = 1; i < size; ++i) {
		if(i % 16 == 0) fprintf(stdout, "\n");
		fprintf(stdout, " %2x", 0xff & mem[i]);
	}
	fprintf(stdout, "\n");
}
		
unsigned char *create_chunk(int size, char *arg)
{
	int i;
	unsigned char *mem;
	mem = (unsigned char *)malloc(size);
	if(!strcmp(arg, "zero")) {
		memset(mem, 0, size);
	} else if(!strcmp(arg, "rand")) {
		for(i = 0; i < size; ++i) {
			mem[i] = (unsigned char) (rand()%0x100);
		}
	} else {
		fprintf(stderr, "undefined arg\n");
	}
	return mem;
}

void destroy_chunk(unsigned char *chunk)
{
	free(chunk);
}

void mult_chunk(unsigned char *in, unsigned char *out, unsigned char *gfrow)
{
	int i;
	for(i = 0; i < CHUNKSIZE; ++i) {
		out[i] = gfrow[in[i]];
	}
}

int main(int argc, char *argv[])
{
	unsigned char *in_chunk = create_chunk(CHUNKSIZE, "rand");
	unsigned char *out_chunk = create_chunk(CHUNKSIZE, "zero");
	dump(in_chunk, CHUNKSIZE);
	dump(out_chunk, CHUNKSIZE);

	unsigned char matrix[] = {0x09, 0x08, 0x0a, 0x08, 0x0a, 0x09,
				  0x0a, 0x08, 0x0a, 0x09, 0x08, 0x09,
				  0x0a, 0x08, 0x09, 0x08, 0x09, 0x08,
				  0x09, 0x08, 0x0a, 0x09, 0x08, 0x0a};
	int i;
	unsigned char s;
	double start, end;
	start = getCPUTime();
	for(i = 0; i < 24; ++i) {
		s = matrix[i];
		mult_chunk(in_chunk, out_chunk, &gf_mul_table_base[s*256]);
	}
	dump(&gf_mul_table_base[(s-1)*256],256); 
	dump(in_chunk, CHUNKSIZE);
	dump(out_chunk, CHUNKSIZE);
	end = getCPUTime();

	fprintf(stdout, "Time takes: %f\n", end-start);	
	destroy_chunk(in_chunk);
	destroy_chunk(out_chunk);
	return 0;
}
