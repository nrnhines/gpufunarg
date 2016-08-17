#include <stdio.h>

extern int a(int, int);

int steer(int i, int ifun);
#pragma acc routine(steer) seq

extern int b(int);
#pragma acc routine(b) seq

extern int c(int);
#pragma acc routine(c) seq

int main() {
  int x;

  x = a(1000, 1);
  printf("x=%d\n", x);

  x = a(1000, 2);
  printf("x=%d\n", x);

  return 0;
}

int a(int n, int ifun) {

  int i, x;
  x = 0;
  #pragma acc parallel loop
  for (int i = 0; i < n ; ++i) {
    #pragma acc atomic update
    x += steer(i, ifun);
  }
  return x;
}

int b(int i) {
  return 2*i;
}

int c(int i) {
  return 3*i;
}

int steer(int i, int ifun) {
  int x;
#if 1
  switch (ifun) {
    case 1: x = b(i); break;
    case 2: x = c(i); break;
  }
#else
  if (ifun == 1) {
    x = b(i);
  }else{
    x = c(i);
  }
#endif
  return x;
}
