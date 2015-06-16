#include "../#Helper/helper.h"

#define SKIP_SPACE(s) while(s && isspace(*s)) ++s
#define SKIP_NONSPACE(s) while(s && *s && !isspace(*s)) ++s
#define SWAP_CHAR(a, b) do { char tmp = a; a = b; b = tmp; } while(0)

void trimStr(char *s) {
  if (!s) return;
  char *cur = s;
  SKIP_SPACE(s);
  while (*s) {
    while (*s && !isspace(*s)) {
      *cur++ = *s++;
    }
    if (isspace(*s)) {
      *cur++ = ' ';
    }
    SKIP_SPACE(s);
  }
  if (isspace(cur[-1])) {
    --cur;
  }
  *cur = '\0';
}

void reverseStr(char *s, int len) {
  if (!s) return;
  char *r = s + len - 1;
  while (r > s) {
    SWAP_CHAR(*s, *r);
    ++s;
    --r;
  }
}

void reverseWords(char *s) {
  if (!s) return;
  trimStr(s);
  reverseStr(s, strlen(s));
  char *t;
  while (*s) {
    t = s;
    SKIP_NONSPACE(t);
    reverseStr(s, t - s);
    if (*t) {
      ++t;
    }
    s = t;
  }
}

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  CLK_INIT;
  CASET{
    char str[1000];
    gets(str);
    //scanf("%s", str);
    PRINTCASE;
    CLK_START;
    reverseWords(str);
    //puts(str);
    printf("[%s]\n", str);
    CLK_END;
  }
  return 0;
}