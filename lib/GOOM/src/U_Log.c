#include "U_Log.h"
#include <stdio.h>

static void init_event(LogEvent_t *event, void *udata) {
  time_t t = time(NULL);
  event->time = localtime(&t);
  event->udata = udata;
}

static void stdout_callback(LogEvent_t *event) {
  char buf[16];
  buf[strftime(buf, sizeof(buf), "%H:%M:%S", event->time)] = '\0';
  fprintf(
    event->udata,
    "%s %s%-5s\x1b[0m \x1b[90m%s:%d:\x1b[0m ",
    buf, level_colors[event->level], level_strings[event->level],
    event->file, event->line
  );
  vfprintf(event->udata, event->fmt, event->ap);
  fprintf(event->udata, "\n");
  fflush(event->udata);
}

void log_log(int level, const char *file, int line, const char *fmt, ...) {
  LogEvent_t event = {
    .fmt = fmt,
    .file = file,
    .line = line,
    .level = level,
  };

  init_event(&event, stderr);
  va_start(event.ap, fmt);
  stdout_callback(&event);
  va_end(event.ap);
}