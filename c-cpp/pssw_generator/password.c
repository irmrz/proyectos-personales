#include <assert.h>
#include <sodium.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

char *random_password(unsigned int length) {
  assert(length >= 5);
  if (sodium_init() == -1) {
    return NULL;
  }

  char *password = malloc((length + 1) * sizeof(char));
  uint_fast8_t ascii_code;

  password[length] = '\0';
  for (unsigned int i = 0; i < length; i++) {
    
  generate:
    ascii_code = randombytes_random() % 128;
    if (((ascii_code < 31) || (ascii_code > 126)) 
      || ((ascii_code == 39) || (ascii_code == 34) )) { goto generate;}
    password[i] = ascii_code;
  }

  return password;
}

char *filename_for_pssw() {

  time_t current_time;
  time(&current_time);
  struct tm *timeinfo;
  timeinfo = localtime(&current_time);

  char *file_time = malloc(9 * sizeof(char));
  strftime(file_time, 9, "%T", timeinfo);

  char *pssw = strdup("password_%s.txt");
  char *filename = malloc(strlen(pssw) + 1 + strlen(file_time));
  sprintf(filename, "password_%s.txt", file_time);

  free(pssw);
  free(file_time);

  return filename;
}

int copy_to_cpbrd(const char *password) {
  const char proto_cmd[] = "echo '%s' | xclip -selection clipboard ";
  char cmd[strlen(password) + strlen(proto_cmd) - 1];
  sprintf(cmd, proto_cmd, password);
  printf("Your password has been copied to clipboard\n");
  return system(cmd);
}
