
#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define LOG_RESET_COLOR   "\033[0m"

#define TRACE_PRINT(TAG, format, args...)                                                                                       \
	do                                                                                                                          \
	{                                                                                                                           \
		char __TRACE_PRINT_cur_system_time[24];                                                                                               \
		struct tm *__TRACE_PRINT_p;                                                                                                           \
		struct timeval __TRACE_PRINT_now;                                                                                                     \
		memset(__TRACE_PRINT_cur_system_time, 0, sizeof(__TRACE_PRINT_cur_system_time));                                                                    \
		gettimeofday(&__TRACE_PRINT_now, NULL);                                                                                               \
		__TRACE_PRINT_p = localtime(&__TRACE_PRINT_now.tv_sec);                                                                                             \
		if (__TRACE_PRINT_p)                                                                                                                  \
		{                                                                                                                       \
			snprintf(__TRACE_PRINT_cur_system_time, sizeof(__TRACE_PRINT_cur_system_time) - 1, "%02d-%02d %02d:%02d:%02d.%03ld", __TRACE_PRINT_p->tm_mon + 1, __TRACE_PRINT_p->tm_mday, \
					 __TRACE_PRINT_p->tm_hour, __TRACE_PRINT_p->tm_min, __TRACE_PRINT_p->tm_sec, __TRACE_PRINT_now.tv_usec / 1000);                                                     \
		}                                                                                                                       \
		printf(TAG ":%s:%s() line:%u%s  " format, __TRACE_PRINT_cur_system_time, __FUNCTION__, __LINE__, LOG_RESET_COLOR,  ##args);                               \
	} while (0)

#define TRACE_INFO(format, args...)                  \
	do                                               \
	{                                                \
		TRACE_PRINT("\033[0;32m[INFO]", format, ##args);   \
	} while (0)







#endif
