#include <stdio.h>
#include <stdlib.h>

// 标准地址 cppreference.com 手册地址
int main()
{
  // 动态内存管理

  // malloc
  /*
    stdlib.h
    void * malloc (size_t size);
    分配size字节的未初始化内存
  */

  // int 型指针 num 赋值为: (int *) 强制转换 : 使用malloc在堆区空间 十万个整型 大小的空间 
  // 等价于 int num[100000];
  // 内部数据是随机的
  int *num = (int * )malloc(100000 * sizeof(int));

  num[0] = 123;
  num[99999] = 999;
  printf("%d , %d, %d, \n", num[0], num[99999], num[1]);

  // 释放完可访问，但较为危险。
  free(num);
  num = NULL;

  // calloc
  /*
    分配并清零内存
  */

  // realloc 
  /*
    重新分配
  */

  // free
  return 0;
}