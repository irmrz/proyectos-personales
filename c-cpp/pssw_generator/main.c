/*
Password generator using the Sodium library to generate random Ascii characters.
*/


#include "password.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

int main() {
  
  //Variables init
  unsigned int char_quantity = 0;
  bool choose = true;
  char *password;

  // Message to user and password size
  printf("How many characters would you like?\n");
  
  while(choose) {  
   printf("Choose a number between 5 and 128\n");
    if (scanf("%u",&char_quantity) != 1 ) {
      printf("Input value is not a number.\n");
      exit(EXIT_FAILURE);
    }
    if ((MIN_CHARACTERS <= char_quantity) && (char_quantity <= MAX_CHARACTERS)) {choose = false;}
  }
 

  //Generating password
  password = random_password(char_quantity);
  printf("Password:\n");
  printf("%s\n",password);

  
  //Saving in file using stick and stones
  copy_to_cpbrd(password); 
  free(password);
  return 0;
}
