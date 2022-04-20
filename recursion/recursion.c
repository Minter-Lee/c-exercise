#include <stdio.h>

// 容易溢出
int factorial(int n) {
  // 判定出口 给出出口 确定值
  if(n == 1) {
    return n;
  } 
  // 非出口 给出相似子问题
  else {
    return n * factorial(n-1);
  }
}

int fibonacci(int n) {
  if(n == 1 || n == 2) {
    return 1;
  } else {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main() {
  int n;
  printf("请输入N：");
  scanf("%d", &n);
  printf("%d 的阶乘是 %d \n", n, factorial(n));
  printf("第 %d 项斐波那契额序列是 %d \n", n, fibonacci(n));
}