#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

//unsigned int SEED = 0xabba;

/*
    Para mejorar la aleatoriedad del programa, la semilla debería 
    venir desde una fuente realmente aleatoria.
    https://docstore.mik.ua/orelly/networking/puis/ch23_08.htm
*/

long int xorshift(long int to) {
    assert(to != 0);
    clock_t x = clock();
    /*clock():
    This function returns the number of clock ticks 
    elapsed since the start of the program.
    */
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;

    return (long int)x % to; // clock_t es similar a long int
}

int main(void) {

    printf("%ld\n",xorshift(1000000));
    printf("%ld\n",xorshift(1000));
    printf("%ld\n",xorshift(100));
    printf("%ld\n",xorshift(10));
}