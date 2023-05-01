#include "functions.hpp"

int main(int argc, char **argv){
    if ((argc < 2) || (argc > 3)) usage();

    int mode;
     
    mode = 1;

    /* Error handling and modes*/
    if (argc == 3) {
        mode = strcmp("-s", argv[1]);
        if (mode != 0) usage();
    }
    if (!isdigit(*argv[argc-1])) usage();

    /* everything happens inside this function*/
    timer(std::stoi(argv[argc-1]), mode);

    return 0;
}