#include <stdio.h>

// 占 8 字节
struct node0 {
  int x, y;
};

// 还是8字节
struct node1 {
  char x;
  int y;
};

// 使用typedef定义别名，方便使用
typedef struct node {
  int x, y;
} node;

// . 和 -> 的区别 普通结构体用. 结构体的指针使用->
int main()
{
  // 未定义别名
  struct node0 a0;

  // 已经定义了别名
  node a;

  a.x = 5;
  a.y = 10;

  printf("a.x = %d, a.y = %d \n", a.x, a.y);

  // (node *) p
  node *p = &a;

  // p指针存储的地址指向的结构体a的x
  p->x = 9;
  p->y = 100;

  printf("a.x = %d, a.y = %d \n", a.x, p->y);

  return 0;
}