#include <stdio.h>

int get_change(int m) {
  
  int tten = m/10;
  m %= 10;
  int tfive = m/5;
  m %= 5;
  return tten + tfive + m;
}

int main() {
  long long m;
  scanf("%lld",&m);
  printf("%d\n",get_change(m));
}
