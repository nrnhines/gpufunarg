#include <stdio.h>

typedef int(*F)(int);
extern int a(int, F);
extern int b(int);

int main() {
  int x;
  x = a(1000, b);
  printf("x=%d\n", x);
  return 0;
}

int a(int n, F f) {
  int i, x;
  x = 0;
  for (i = 0; i < n ; ++i) {
    x += (*f)(i);
  }
  return x;
}

int b(int i) {
  return 2*i;
}
