#include <stdio.h>

// 判定回文数
int isPalindromeNum(num)
{
  int revereNum = 0, n = num;

  while (n != 0)
  {
    // 取n最后一位放入revere第一位
    revereNum = revereNum * 10 + n % 10;
    // 删除 n 最后一位
    n /= 10;
  }

  return revereNum == num;
}

// 最大回文乘积 9009 = 91 * 99 2位数相乘最大的回文数，现求三位数相乘得到的最大的回文数
int main()
{
  int ans = 0, a = 100, b = 100;

  for (int i = 100; i < 1000; i++)
  {
    for (int j = i; j < 1000; j++)
    {
      int num = i * j;
      if (isPalindromeNum(num) && ans < num)
      {
        ans = num;
        a = j;
        b = j;
      }
    }
  }

  printf("3 位数相乘的最大回文数是： %d \n", ans);
  printf("3 位数相乘的最大回文数的3位数是： a = %d, b = %d \n", a, b);

  return 0;
}