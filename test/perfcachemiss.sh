#!/bin/bash

perf record -e L1-dcache-load-misses,L1-dcache-store-misses,cache-misses $1
