#include <stdio.h>

// 求斐波那契数列小于四百万的项的偶数和
int main()
{
  int a = 1, b = 2, ans = 0;

  while (b < 4000000)
  {
    if (b % 2 == 0) {
      ans += b;
    }
    b = b + a;
    a = b - a;
  }

  printf(" %d \n", ans);
  return 0;
}