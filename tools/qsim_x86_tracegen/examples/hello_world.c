#include <qsim_magic.h>
#include <stdio.h>
int main() {
  qsim_magic_enable();
  printf("Hello World!\n");
  qsim_magic_disable();
  return 0;
}
