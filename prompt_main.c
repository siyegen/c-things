#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef void sigfunc(int);

#ifdef _WIN32
#include <string.h>
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}
void add_history(char* unused){}

#else
#include <editline/readline.h>
#endif

typedef int bool;
#define true 1
#define false 0
bool* stop = false;

void sig_handler(int signo) {
  if(signo == SIGINT) {
    puts("Caught SIGINT");
    *stop = true;
  }
}

int main(int argc, char** argv) {

  puts("Lispy Version 0.0.0.0.1");
  puts("Press Ctrl+C to exit\n");

  while(1 && stop == false) {
    char* input = readline("lispy> ");
    add_history(input);

    printf("Confirming input: %s\n", input);
    free(input);
  }

  return 0;
}
