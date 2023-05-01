#ifndef _ENTRY_H
#define _ENTRY_H

#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define CREDIT 0
#define DEBIT 1
#define SPACE " "
#define HISTORY 10
#define CREDIT_DEBIT 20
#define AMOUNT_ENTRY_VARS 5
#define DESC_MAX_LENGTH 50
#define EXPECTED_FORMAT "#%u\t%s\t$%f\t%s\t%s\n"

/* Type definitions */

typedef struct _s_entry * entry;

typedef entry EntryTable[];


/* Constructors */

entry new_entry(char *type_op, double value,char *description);

void destroy_entry(entry e);


/* Functions*/

char* currentDateTime(void);

char* print_entry(entry e);

void entry_to_file (FILE *file, entry entry);

entry entry_from_file(FILE file);

unsigned int get_entries(const char *input);

void update_entries(const char *input);

void usage(void);

void array_from_file(const char *filepath, EntryTable array);

#endif