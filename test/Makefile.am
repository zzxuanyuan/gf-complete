# GF-Complete 'test' AM file

AM_CPPFLAGS = -I$(top_builddir)/include -I$(top_srcdir)/include
AM_CFLAGS = -O3 $(SIMD_FLAGS) -fPIC

bin_PROGRAMS = gf_unit
bin_PROGRAMS += test_cache_presetmem
bin_PROGRAMS += test_cache_prezeromem
bin_PROGRAMS += test_L1_cache
bin_PROGRAMS += clean_cache
bin_PROGRAMS += test_thread
bin_PROGRAMS += test_table

gf_unit_SOURCES = gf_unit.c
test_cache_presetmem_SOURCES = test_cache_presetmem.c
test_cache_prezeromem_SOURCES = test_cache_prezeromem.c
test_L1_cache_SOURCES = getcputime.c test_L1_cache.c
clean_cache_SOURCES = clean_cache.c
test_thread_SOURCES = getcputime.c gf_default_table.c test_thread.c
test_table_SOURCES = getcputime.c test_table.c

#gf_unit_LDFLAGS = -lgf_complete
gf_unit_LDADD = ../src/libgf_complete.la
test_table_LDADD = ../src/libgf_complete.la
test_table_LDFLAGS = -lrt
test_L1_cache_LDFLAGS = -lrt
test_thread_LDADD = ../src/libgf_complete.la
test_thread_LDFLAGS = -lrt -lpthread
