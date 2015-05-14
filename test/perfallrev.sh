#!/bin/bash

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread composite > perf_composite

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread split > perf_split

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread default > perf_default

