/*
Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.
*/

#include <stdio.h>

#define TRUE 1
int my_strend(const char *s, const char *t) {
  int size_S, size_T, exit;
  size_S = size_T = exit = 0;
  printf("s = %s\n", s);
  printf("t = %s\n", t);
  while (*s != '\0' && (s++, size_S++, 1));
  while (*t != '\0' && (t++, size_T++, 1));
  s -= size_T, t -= size_T;
  printf("s: %c, t: %c\t", *s, *t);
  if (size_S && size_T && (size_S >= size_T)) {
    while (*s++ == *t++) printf("s: %c, t: %c\t", *s, *t);
    if (!(*s)) exit = TRUE;
  }
  printf("\n");
  return exit;
}

int main() {
  char s[] = "tu vieja en tanga";
  char t1[] = "en tanga";
  char t2[] = "         en tanga";
  char t3[] = "";
  char t4[] = "tu vieja en tanga";
  char t5[] = "123";
  char t6[] = "en tanga  ";
  printf("strend: %d\n", my_strend(s,t1));
  printf("strend: %d\n", my_strend(s,t2));
  printf("strend: %d\n", my_strend(s,t3));
  printf("strend: %d\n", my_strend(s,t4));
  printf("strend: %d\n", my_strend(s,t5));
  printf("strend: %d\n", my_strend(s,t6));
  return 0;
}