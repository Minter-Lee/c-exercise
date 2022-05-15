#include <stdio.h>

int main()
{
  int a = 5, b = 10;
  // int * 表示定义指针
  int *p = &a;

  printf("a = %d\n", a);
  printf("*p = %d\n", *p);

  p = &b;
  printf("b = %d\n", b);
  // *p 代表 取地址对应的值；
  printf("*p = %d\n", *p);

  int num[105] = {9, 8, 7};

  // 数组名即代表数据首地址
  int *q = num;
  q[1] = 100;
  printf("%d, %d, %d, %d, %d\n", num[0], num[1], num[2], *q, *(q + 1));
  printf("num size = %lu, q size = %lu, *q size = %lu \n", sizeof(num), sizeof(q), sizeof(*q));

  return 0;
}