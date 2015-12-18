#include <stdio.h>


typedef struct {
  float x;
  float y;
} point;

int add_two_int(int x, int y) {
  int result = x + y;
  return result;
}

float add_two(float x, float y) {
  float result = x + y;
  return result;
}

void print_hello(char* msg, int times) {
  int i=0;
  while (i++<times) {
    puts(msg);
  }
}

int main(int argc, char** argv) {
  puts("Yoyo, world");
  int int_result = add_two_int(4, 5);
  float float_result = add_two(4.0f, 5.0f);
  printf("results: %d and %.1f\n", int_result, float_result);
  print_hello("yo world", 4);

  return 0;
}
