#include "functions.h"

unsigned int entries = 0;

struct _s_entry
{
    unsigned int entry_number;
    char* description;
    double value;
    char* type;
    char* date_time;
};

entry new_entry(char *type_op, double value,char *description) {
    assert((strcmp(type_op, "-c") == 0) || (strcmp(type_op, "-d") == 0));
    entry result = malloc(sizeof(struct _s_entry));
    
    result->entry_number = get_entries("txt.txt");
    update_entries("entries.txt");
    result->type = type_op;
    result->value = value;
    result->description = description;
    result->date_time = currentDateTime();

    return result;
}

void destroy_entry(entry e) {
    char *killme = e->date_time;
    free(e);
    free(killme);
    e = NULL;
}

char* currentDateTime(void) {
    /* Format of final string: hh:mm dd/mm/yy */
    char *current_time = malloc(sizeof(char) * 17);

    time_t raw;
    raw = time(NULL);
    struct tm *now = localtime(&raw);

    size_t extra = strftime(current_time,17, "%H:%M %d/%m/%Y",now);
    assert(extra == strlen(current_time));
    return current_time;
}


char* print_entry(entry e) {
    char* output = "";
    e->description = output;
    return output;
}


void entry_to_file (FILE *file, entry entry) {
    assert(file != NULL);
    const char *type;
    
    if (strcmp(entry->type, "-c"))
    {
        type = "CREDIT";
    }
    else if (strcmp(entry->type, "-d"))
    {
        type = "DEBIT";
    }
    
    fprintf(file, EXPECTED_FORMAT, entry->entry_number, entry->description,
    entry->value, type, entry->date_time);
}

unsigned int get_entries(const char *input) {
    unsigned int entries;
    char c;

    entries = 0;
    FILE *file = fopen(input, "r+");
    if (file == NULL)
    {
        printf("Error\n");
    }

    for (c = getc(file); c != EOF; c = getc(file))
    {
        if (c == '\n') entries++;     
    }
    
    fclose(file);

    return entries;
}

void update_entries(const char *input) {
    char buffer[25];
    unsigned int entries;


    buffer[24] = '\0';
    FILE *file = fopen(input, "r+");
    entries = get_entries("txt.txt");
    entries++;
    snprintf(buffer, sizeof(buffer), "echo %u > entries.txt", entries);
    system(buffer);

    fclose(file);
}

void usage(void) {
    printf("Todo mal loco\n");
}
/*
void array_from_file(const char *filepath, EntryTable array) {
}
*/