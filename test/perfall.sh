#!/bin/bash
#==================== default ====================#
./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread default 1 > perf_default_1thread

./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread default 2 > perf_default_2thread

./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread default 3 > perf_default_3thread

./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread default 4 > perf_default_4thread

#==================== split ====================#

./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread split 1 > perf_split_1thread

./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread split 2 > perf_split_2thread

./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread split 3 > perf_split_3thread

./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread split 4 > perf_split_4thread

#==================== composite ====================#

./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread composite 1 > perf_composite_1thread

./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread composite 2 > perf_composite_2thread

./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread composite 3 > perf_composite_3thread

./clean_cache

perf stat -e L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses,LLC-loads,LLC-stores,LLC-prefetches,cache-references,cache-misses,alignment-faults ./test_thread composite 4 > perf_composite_4thread

./clean_cache
