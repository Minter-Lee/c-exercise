#include <stdio.h>
#include <string.h>
#include <limits.h>

#define Fun(x, y) (x + 2) * y;

void sub(int *a, int *b)
{
  int t;
  t = *a + *b;
  *a = t - *a;
  *b = t - *b;
}

void subMain()
{
  int x = 3, y = 4, s;
  sub(&x, &y);
  s = 36 / Fun(x, y);
  // 18
  printf("s=%d\n", s);
}

// 地址交换 4分
void transByPoint()
{
  int a = 6, b = 12;
  int *p, *p1, *p2;

  p1 = &a, p2 = &b;

  p = p1;
  p1 = p2;
  p2 = p;

  // 12, 6
  printf("x=%d, y=%d \n", *p1, *p2);
}

void fun1()
{
  char *p = "abcdefgh";

  // 注意此处的运算方法，先++再取地址
  while (*(p++) != 'e')
    ;
  // 注意上述分号，表明为空语句，*p++后是f
  printf("%c \n", *p);
  // 此处打印的是字符串
  printf("%s\n", p);
}

void fun2()
{
  int i = 1, a[] = {0, 2, 4}, *b;
  b = &i;
  // 首地址往后挪了以为，即为a[1]的地址
  // *(a + 1) == *(a + *b) == a[1];
}

// 带入指针来判定回文
void fun3()
{
  char ch[81], *p = ch, *q;
  gets(p);
  q = p + strlen(p) - 1;
  while (p < q)
  {
    if (*p == *q)
    {
      p++;
      q--;
    }
    else
    {
      break;
    }
  }

  if (p < q)
  {
    printf("该字符串是回文！\n");
  }
  else
  {

    printf("该字符串不是回文！\n");
  }
}

void fun4(int *s, int *y)
{
  // 只执行一次
  static int t = 3;
  *y = s[t];
  // 此处每次减一 3,2,1,0
  t--;
}

void fun5()
{
  int a[] = {10, 20, 30, 40}, i, x = 0;
  for (i = 0; i < 4; i++)
  {
    fun4(a, &x);
    // 40,30,20,10
    printf("%d", x);
  }
  printf("\n");
}

void base()
{
  int a[5] = {10, 20, 30, 40, 50};
  int *p = a;
  // printf("result = %d \n", *p); // 10
  // printf("result = %d \n", *(p+1)); // 20
  // // 10 结合性自右向左，但++号在后面所以 prinf先执行 ++的意思为printf的后++
  // printf("result = %d \n", *p++);
  // printf("result = %d, %d \n", *(++p), ++(*p));
  printf("a[2] = %d, p[2] = %d \n", a[2], p[2]); // 30
}

void pointIntputAndOutput()
{

  int *p, a[10], i;
  // 赋值
  p = a;
  // 录入
  for (i = 0; i < 10; i++)
  {
    printf("请输入数据第%d个数: ", i + 1);
    scanf("%d", p++);
    // 快速赋值
    // *p++=i;
  }
  // 因为录入的关系，重置指针值a首地址
  p = a;
  // 输出
  for (i = 0; i < 10; i++)
  {
    printf("a[%d] = %d \n", i, *p++);
  }
}

// 删除最小项
void removeMinItem()
{

  // 输入并查找出最小值
  int arr[100], *p, i = 0;
  int min = INT_MAX, minIndex;

  p = arr;

  do
  {
    printf("请输入第%d个数据", i + 1);
    scanf("%d", p + i);
    if (arr[i] < min)
    {
      min = arr[i];
      minIndex = i;
    }
    i++;
  } while (i < 6);

  // 使用循环覆盖方式进行删除
  for (int j = minIndex + 1; j < i; j++)
  {
    *(p + j - 1) = *(p + j);
  }

  // 注意删除了一个，所以少输出一次,C语言只能覆盖没有释放空间的能力（直接delete能力）
  for (int j = 0; j < i - 1; j++)
  {
    printf("array[%d] = %d \n", j, *(p + j));
  }
}

// 数组做参数，子函数执行数组加一
void addOne(int *p)
{
  for (int i = 0; i < 10; i++)
  {
    // 数组项+1
    (*p)++;
    // 打印当前项并且指针指向下一个
    printf("arr[%d] = %d, \n", i, *(p++));
  }
}

void twoDArray()
{
  int a[3][4] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // int *p = a;
  // 首地址
  printf("%p,", a);
  // 首地址
  printf("%p,", *a);
  // 首地址
  printf("%p,", a[0]);
  // 内容
  printf("%d,", *a[0]);
  // 首地址
  printf("%p,", &a[0]);
  // 首地址
  printf("%p \n", &a[0][0]);
}

void twoDArrayPoint()
{
  int a[3][4] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // 二维数组指针，中括号为列数
  int(*p)[4];
  p = a;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      printf("%d \t", *(*(p + i) + j));
    }
  }
  printf("\n");
}

void fun6(int i, char *cp)
{
  for (; i; i--)
  {
    printf("%c", *cp++);
  }
}

void fun6Main()
{
  char a[][3] = {"ABC", "DEF", "GH"};
  // 注意这是个一维数组指针变量
  char *p;
  p = a[0];
  // A
  fun6(1, p++);
  // p 指向了B 显示B，cp被覆盖了，所以上述cp++没起作用
  fun6(1, p++);
  // p 指向了C 显示C
  fun6(1, p++);
  printf("\n");

  p = a[1];
  // DEF
  fun6(3, p++);
  // EF
  fun6(2, p++);
  // F
  fun6(1, p);
  printf("\n");

  // ABCDEFGH
  printf("%s \n", a[0]);
}

void fun7Main()
{
  char a[3][10] = {"beijing", "shanghai", "chengdu"}, *p1, (*p2)[10];
  p1 = a[0];
  p2 = a;
  // h
  printf("%c \n", *(a[1] + 1));
  // a
  printf("%c \n", *(*(a + 1) + 2));
  // e
  printf("%c \n", *(p1 + 1));
  // a
  printf("%c \n", *(*(p2 + 1) + 2));

  // eiing
  printf("%s \n", p1 + 1);
  // chengdu
  printf("%s \n", p2[2]);
  // shanghai
  printf("%s \n", *(p2 + 1));
}

void pointArray()
{
  int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  int *p[3] = {a[0], a[1], a[2]};
  for (int i = 0; i < 3; i++)
  {
    printf("%d, %d, %d, %d \n", *p[i], *(p[i]+1), *(p[i]+2), *(p[i]+3));
  }
}

int main()
{
  // int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  // addOne(array);
  // removeMinItem();
  // twoDArray();
  // twoDA rrayPoint();
  // fun6Main();
  pointArray();
  return 0;
}