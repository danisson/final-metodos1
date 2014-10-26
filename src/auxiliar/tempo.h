#ifndef TIMEHELPH
#define TIMEHELPH
#include <sys/time.h>
#include <ctime>

typedef unsigned long long timestamp_t;

timestamp_t get_timestamp ();
#endif