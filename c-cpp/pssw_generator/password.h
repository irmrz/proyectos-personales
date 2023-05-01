#include <sodium.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#define MAX_CHARACTERS 128
#define MIN_CHARACTERS 5

//Function name is self explanatory
char *random_password(unsigned int length);

char *filename_for_pssw(void);

void copy_to_cpbrd(const char *password);
