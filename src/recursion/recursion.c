#include <stdio.h>

// 容易溢出
int factorial(int n) {
  // 判定出口 给出出口 确定值
  if(n == 1 || n == 0) {
    return n;
  } 
  // 非出口 给出相似子问题
  else {
    /* 不能执行n-- 或者 --n 因为编译后的结果可能影响 n的取值
      可能编译为
      n--;
      n * n;
    */
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

// 判断递增数组, n是第多少项 n = 10 则 a[9]为第10项
int increment(int a[], int n) {
  if(n == 1) {
    return 1;
  } else if(n == 2) {
    return a[1] > a[0];
  } else {
    // 判定每一次递归的结果全为真才可 n
    return increment(a, n-1) && (a[n-1] >= a[n-2]);
  }
}

// 北航2021 正整数转为字符串 583 => "583"
void convertIntToChar(int num) {
  int i;
  // 取整 583/10 => 58
  i = num/10;
  // 取整不为零即取到了最后一位了（最高位 5 ）
  if(i) {
    convertIntToChar(i);
  }
  // 输出字符串
  putchar(num%10 + '0');
}

// 打印所有 三位数阶乘之和 等于这三位数
void find145() {
  for(int i = 100; i<1000; i++) {
    // 拆解三位数的个十百位
    int a = i / 100;
    int b = (i / 10) % 10;
    int c = i % 10;
    // printf("拆解的三位 %d, %d, %d\n", a, b, c);
    if(i == factorial(a) + factorial(b) + factorial(c)) {
      printf("三位数与拆解的三位阶乘之和的数是 abc = a!+b!+c! %d \n", i);
    }
  }
}

int main() {
  // int n;
  // printf("请输入N：");
  // scanf("%d", &n);
  // printf("%d 的阶乘是 %d \n", n, factorial(n));
  // printf("第 %d 项斐波那契额序列是 %d \n", n, fibonacci(n));
  // convertIntToChar(123);
  find145();
}