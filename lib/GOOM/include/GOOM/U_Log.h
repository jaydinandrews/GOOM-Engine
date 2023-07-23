#ifndef LOG_H 
#define LOG_H

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#define LOG_DEBUG 0
#define LOG_INFO 1
#define LOG_WARN 2
#define LOG_ERROR 3
#define LOG_CRITICAL 4

#define log_debug(...) log_log(LOG_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define log_info(...) log_log(LOG_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define log_warn(...) log_log(LOG_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define log_error(...) log_log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define log_critical(...) log_log(LOG_CRITICAL, __FILE__, __LINE__, __VA_ARGS__)

static const char *level_strings[] = {
  "DEBUG",
  "INFO",
  "WARN",
  "ERROR",
  "CRITICAL"
};

static const char *level_colors[] = {
  "\x1B[34m", // blue
  "\x1B[37m",  // white
  "\x1B[33m",  // yellow
  "\x1B[31m",  // red
  "\x1B[1;31m" // bold red
};

typedef struct LogEvent_s {
  va_list ap;
  const char *fmt;
  const char *file;
  struct tm *time;
  void *udata;
  int line;
  int level;
} LogEvent_t;

void log_log(int level, const char *file, int line, const char *fmt, ...);

#endif /* LOG_H */