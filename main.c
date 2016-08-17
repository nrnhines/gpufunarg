#include <stdio.h>

typedef struct {
  int(*f)(int);
} F;

extern int a(int, F);
extern int b(int);

int main() {
  int x;
  F f;
  f.f = b;

  x = a(1000, f);
  printf("x=%d\n", x);
  return 0;
}

int a(int n, F f) {
  int i, x;
  x = 0;
  for (i = 0; i < n ; ++i) {
    x += (*(f.f))(i);
  }
  return x;
}

int b(int i) {
  return 2*i;
}
