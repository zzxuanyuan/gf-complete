#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gf_complete.h"
#include "getcputime.h"
#include "ec_base.h"

//#define CHUNKSIZE 16384
//#define CHUNKSIZE 262144
#define CHUNKSIZE 4194304
//#define CHUNKSIZE 67108864
//#define CHUNKSIZE 1073741824

void dump(unsigned char *mem, long long size)
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
		
unsigned char *create_chunk(long long size, char *arg)
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
//	dump(in_chunk, CHUNKSIZE);
//	dump(out_chunk, CHUNKSIZE);

	unsigned char matrix[] = {0x09, 0x08, 0x0a, 0x08, 0x0a, 0x09,
				  0x0a, 0x08, 0x0a, 0x09, 0x08, 0x09,
				  0x0a, 0x08, 0x09, 0x08, 0x09, 0x08,
				  0x09, 0x08, 0x0a, 0x09, 0x08, 0x0a};
	int i;
	unsigned char s;
	double start = 0.0;
	double end = 0.0;
//	dump(in_chunk, CHUNKSIZE);
//	dump(out_chunk, CHUNKSIZE);
	gf_t gf;
//	gf_init_easy(&gf, 8);
	if(gf_init_hard(&gf, 16, GF_MULT_SPLIT_TABLE, GF_REGION_ALTMAP, GF_DIVIDE_DEFAULT, 0, 16, 4, NULL, NULL)==0) {
		fprintf(stderr, "gf_init_hard failed\n");
		return 1;
	}
	start = getCPUTime();
	for(i = 0; i < 24; ++i){
		s = matrix[i];
		gf.multiply_region.w32(&gf, in_chunk, out_chunk, s, CHUNKSIZE, 0);
	}
	end = getCPUTime();
//	dump(in_chunk, CHUNKSIZE);
//	dump(out_chunk, CHUNKSIZE);
	fprintf(stdout, "Time takes(SIMD instr): %f\n", end-start);
	destroy_chunk(in_chunk);
	destroy_chunk(out_chunk);

	in_chunk = create_chunk(CHUNKSIZE, "rand");
	out_chunk = create_chunk(CHUNKSIZE, "zero");
	start = getCPUTime();
	for(i = 0; i < 24; ++i) {
		s = matrix[i];
		mult_chunk(in_chunk, out_chunk, &gf_mul_table_base[s*256]);
	}
	end = getCPUTime();
//	dump(&gf_mul_table_base[(s-1)*256],256); 
//	dump(in_chunk, CHUNKSIZE);
//	dump(out_chunk, CHUNKSIZE);
	fprintf(stdout, "Time takes(fetch table): %f\n", end-start);	
	destroy_chunk(in_chunk);
	destroy_chunk(out_chunk);

	unsigned char *matrix_locality = (unsigned char *)malloc(1024);
	for(i = 0; i < 1024; ++i) {
		matrix_locality[i] = (rand()%0x4)+0x4;
	}
	dump(matrix_locality, 1024);
	in_chunk = create_chunk(CHUNKSIZE, "rand");
	out_chunk = create_chunk(CHUNKSIZE, "zero");
	start = getCPUTime();
	for(i = 0; i < 1024; ++i){
		s = matrix_locality[i];
		gf.multiply_region.w32(&gf, in_chunk, out_chunk, s, CHUNKSIZE, 0);
	}
	end = getCPUTime();
//	dump(in_chunk, CHUNKSIZE);
//	dump(out_chunk, CHUNKSIZE);
	fprintf(stdout, "Time takes(matrix locality): %f\n", end-start);
	free(matrix_locality);
	destroy_chunk(in_chunk);
	destroy_chunk(out_chunk);

	unsigned char *matrix_random = (unsigned char *)malloc(1024);
	for(i = 0; i < 1024; ++i) {
		matrix_random[i] = rand()%0x100;
	}
	dump(matrix_random, 1024);
	in_chunk = create_chunk(CHUNKSIZE, "rand");
	out_chunk = create_chunk(CHUNKSIZE, "zero");
	start = getCPUTime();
	for(i = 0; i < 1024; ++i){
		s = matrix_random[i];
		gf.multiply_region.w32(&gf, in_chunk, out_chunk, s, CHUNKSIZE, 0);
	}
	end = getCPUTime();
//	dump(in_chunk, CHUNKSIZE);
//	dump(out_chunk, CHUNKSIZE);
	fprintf(stdout, "Time takes(matrix random): %f\n", end-start);
	destroy_chunk(in_chunk);
	destroy_chunk(out_chunk);
	free(matrix_random);

	return 0;
}
