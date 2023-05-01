#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

long long int xorshift64(long long int state) {
  long long int x = state;
  x ^= x << 13;
  x ^= x >> 17;
  x ^= x << 5;
  return x;
}

int main() {
  long long int s;
  printf("Ingrese la semilla: \n");
  scanf("%lld",&s);
  for (long long int i = 0; i < 20; i++)
  {
    printf("%lld\n",xorshift64(s+i<<i | i));
  }

  return EXIT_SUCCESS;
}
