#ifndef _TIMER_H
#define _TIMER_H

#include <iostream>
#include <ctime>
#include <chrono>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iomanip>
#include <string.h>
#include <ctype.h>

enum modes{segundos, minutos};

/* Print function for clarification */
void usage();

/* Main timer function */
void timer( int n, int mode);

/* Display timer */
void display( int hr,  int min,  int sec);

#endif