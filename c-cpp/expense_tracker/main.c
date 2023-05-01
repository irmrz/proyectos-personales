#include "functions.h"

int main(int argc, char** argv) {
    int cases;
    char *time, *desc;
    
    cases = (strcmp(argv[1], "-h") == 0) ? HISTORY : CREDIT_DEBIT;
    FILE *file = fopen("txt.txt", "a+");
    
    if (cases == HISTORY) {
        printf("Todavia nada\n");
    }

    else if (cases == CREDIT_DEBIT) {
        time = currentDateTime();
        desc = malloc(sizeof(char) * DESC_MAX_LENGTH);
        desc = strcpy(desc, argv[argc-1]);
        entry entry1 = new_entry(argv[1], atof(argv[2]), desc);  
        entry_to_file(file, entry1);
        destroy_entry(entry1);
        free(time);
        free(desc);   
        fclose(file);
    }

    else
    {
        printf("Error\n");
    }
    
    
    return 0;
}