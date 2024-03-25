#include <stdio.h>

int lower(int c) {
    /* convert c to lower case; ASCII only */
    /* return condition ? expression1 : expression2;
    */
  return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : (c);
}

int main() {
  printf("Lower M is %c\n", lower('M'));
  printf("Lower x is %c\n", lower('x'));
  printf("Lower @ is %c\n", lower('@'));
  printf("Lower e is %c\n", lower('e'));
}
