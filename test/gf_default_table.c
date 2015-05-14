#include <stdio.h>
#include <getopt.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "gf_complete.h"
#include "gf_rand.h"
#include "gf_default_table.h"
#include "getcputime.h"

int gf_default_table(void)
{
  printf("run gf_default_table()\n");
  uint32_t a, b, c;
  uint8_t *r1, *r2;
  uint16_t *r16 = NULL;
  uint32_t *r32 = NULL;
  int w = 16, i;
  gf_t gf;

  MOA_Seed(time(0));
  a = MOA_Random_W(w, 0);
  b = MOA_Random_W(w, 0);
//  a = rand() % (1<<w);
//  b = rand() % (1<<w);

  gf_init_easy(&gf, w);

  c = gf.multiply.w32(&gf, a, b);
  printf("%u * %u = %u\n", a, b, c);

  printf("%u / %u = %u\n", c, a, gf.divide.w32(&gf, c, a));
  printf("%u / %u = %u\n", c, b, gf.divide.w32(&gf, c, b));

  if (w == 4 || w == 8 || w == 16 || w == 32) {
    r1 = (uint8_t *) malloc(B4M);
    r2 = (uint8_t *) malloc(B4M);

    if (w == 4 || w == 8) {
      r1[0] = b;
      for (i = 1; i < B4M; i++) r1[i] = MOA_Random_W(8, 1);
    } else if (w == 16) {
      r16 = (uint16_t *) r1;
      r16[0] = b;
      for (i = 1; i < B4M/2; i++) r16[i] = MOA_Random_W(16, 1);
    } else {
      r32 = (uint32_t *) r1;
      r32[0] = b;
      for (i = 1; i < B4M/4; i++) r32[i] = MOA_Random_W(32, 1);
    }

    double startTime = 0.0;
    double endTime = 0.0;
    startTime = getCPUTime();
    gf.multiply_region.w32(&gf, r1, r2, a, B4M, 0);
    endTime = getCPUTime();
    printf("Time takes: %f (ms)\n", endTime-startTime);
  }

  exit(0);
}

int gf_split_table(void)
{
  printf("run gf_split_table()\n");
  uint32_t a, b, c;
  uint8_t *r1, *r2;
  uint16_t *r16 = NULL;
  uint32_t *r32 = NULL;
  int w = 16, i;
  gf_t gf;

  MOA_Seed(time(0));
  a = MOA_Random_W(w, 0);
  b = MOA_Random_W(w, 0);
//  a = rand() % (1<<w);
//  b = rand() % (1<<w);

  gf_init_hard(&gf, 16, GF_MULT_SPLIT_TABLE, GF_REGION_ALTMAP, GF_DIVIDE_DEFAULT, 
                   0, 16, 4, NULL, NULL);

  c = gf.multiply.w32(&gf, a, b);
  printf("%u * %u = %u\n", a, b, c);

  printf("%u / %u = %u\n", c, a, gf.divide.w32(&gf, c, a));
  printf("%u / %u = %u\n", c, b, gf.divide.w32(&gf, c, b));

  if (w == 4 || w == 8 || w == 16 || w == 32) {
    r1 = (uint8_t *) malloc(B4M);
    r2 = (uint8_t *) malloc(B4M);

    if (w == 4 || w == 8) {
      r1[0] = b;
      for (i = 1; i < B4M; i++) r1[i] = MOA_Random_W(8, 1);
    } else if (w == 16) {
      r16 = (uint16_t *) r1;
      r16[0] = b;
      for (i = 1; i < B4M/2; i++) r16[i] = MOA_Random_W(16, 1);
    } else {
      r32 = (uint32_t *) r1;
      r32[0] = b;
      for (i = 1; i < B4M/4; i++) r32[i] = MOA_Random_W(32, 1);
    }

    double startTime = 0.0;
    double endTime = 0.0;
    startTime = getCPUTime();
    gf.multiply_region.w32(&gf, r1, r2, a, B4M, 0);
    endTime = getCPUTime();
    printf("Time takes: %f (ms)\n", endTime-startTime);
  }

  exit(0);
}

int gf_composite(void)
{
  printf("run gf_composite()\n");
  uint32_t a, b, c;
  uint8_t *r1, *r2;
  uint16_t *r16 = NULL;
  uint32_t *r32 = NULL;
  int w = 16, i;
  gf_t gf, gf_8;

  MOA_Seed(time(0));
  a = MOA_Random_W(w, 0);
  b = MOA_Random_W(w, 0);

  if (gf_init_hard(&gf_8, 8, GF_MULT_LOG_TABLE, GF_REGION_DEFAULT, GF_DIVIDE_DEFAULT,
                   0, 0, 0, NULL, NULL) == 0) {
    fprintf(stderr, "gf_init_hard (8) failed\n");
    exit(1);
  }

  if (gf_init_hard(&gf, 16, GF_MULT_COMPOSITE, GF_REGION_ALTMAP, GF_DIVIDE_DEFAULT, 
                   0, 2, 0, &gf_8, NULL) == 0) {
    fprintf(stderr, "gf_init_hard (16) failed\n");
    exit(1);
  }

  c = gf.multiply.w32(&gf, a, b);
  printf("%u * %u = %u\n", a, b, c);

  printf("%u / %u = %u\n", c, a, gf.divide.w32(&gf, c, a));
  printf("%u / %u = %u\n", c, b, gf.divide.w32(&gf, c, b));

  if (w == 4 || w == 8 || w == 16 || w == 32) {
    r1 = (uint8_t *) malloc(B4M);
    r2 = (uint8_t *) malloc(B4M);

    if (w == 4 || w == 8) {
      r1[0] = b;
      for (i = 1; i < B4M; i++) r1[i] = MOA_Random_W(8, 1);
    } else if (w == 16) {
      r16 = (uint16_t *) r1;
      r16[0] = b;
      for (i = 1; i < B4M/2; i++) r16[i] = MOA_Random_W(16, 1);
    } else {
      r32 = (uint32_t *) r1;
      r32[0] = b;
      for (i = 1; i < B4M/4; i++) r32[i] = MOA_Random_W(32, 1);
    }

    double startTime = 0.0;
    double endTime = 0.0;
    startTime = getCPUTime();
    gf.multiply_region.w32(&gf, r1, r2, a, B4M, 0);
    endTime = getCPUTime();
    printf("Time takes: %f (ms)\n", endTime-startTime);
  }

  exit(0);
}
