#pragma once
#include <cstdio>

#ifndef LOG_LEVEL
#  define LOG_LEVEL 4  // default for debug
#endif

#define LOG_ERROR(...)  do { if (LOG_LEVEL>=1) { __VA_ARGS__; } } while(0);
#define LOG_WARN(...)   do { if (LOG_LEVEL>=2) { __VA_ARGS__; } } while(0);
#define LOG_INFO(...)   do { if (LOG_LEVEL>=3) { __VA_ARGS__; } } while(0);
#define LOG_DEBUG(...)  do { if (LOG_LEVEL>=4) { __VA_ARGS__; } } while(0);
#define LOG_TRACE(...)  do { if (LOG_LEVEL>=5) { __VA_ARGS__; } } while(0);