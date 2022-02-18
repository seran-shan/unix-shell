#ifndef _ALARM_H
#define _ALARM_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

typedef struct alarm {
    pid_t pid;
    pid_t ppid;
    time_t time;
} alarm;

#endif // _ALARM_CANCEL_H