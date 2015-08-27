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
#include "getcputime.h"

#ifndef B4M
#define B4M	4194304
#endif
#ifndef B1G
#define B1G	1073741824
#endif

#ifdef __cplusplus
extern "C" {
#endif

void *gf_default_table(void *arg);

void *gf_split_table(void *arg);

void *gf_composite(void *arg);

#ifdef __cplusplus
}
#endif

#endif
