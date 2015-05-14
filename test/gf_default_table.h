#ifndef GF_DEFAULT_TABLE_H
#define GF_DEFAULT_TABLE_H

#include <stdio.h>
#include <getopt.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "gf_complete.h"
#include "gf_rand.h"

#ifndef B4M
#define B4M	4194304
#endif
#ifndef B1G
#define B1G	1073741824
#endif

#ifdef __cplusplus
extern "C" {
#endif

int gf_default_table(void);
int gf_split_table(void);
int gf_composite(void);

#ifdef __cplusplus
}
#endif

#endif