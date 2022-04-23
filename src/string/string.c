
#include <stdio.h>
#include <string.h>

// 删除字符串s中所有的空白符，空格 Tab字符 回车符 换行符
// 删除的实现方式是 复制法、循环覆盖法
// 复制法
void deleteSpace(char *s)
{
  int i, t;
  char c[80];
  for (i = 0, t = 0; s[i]; i++)
  {
    if (s[i] != '\n' && s[i] != '\t' && s[i] != ' ')
    {
      c[t++] = s[i];
    }
  }
  c[t] = '\0';
  strcpy(s, c);
};

// 删除尾部空白字符
int trim(char *s)
{
  int n;
  for (n = strlen(s) - 1; n >= 0; n--)
  {
    if (s[n] != '\n' && s[n] != '\t' && s[n] != ' ')
    {
      break;
    }
  }
  // n是下标，所以+1给下一位补一个结束符
  s[++n] = '\0';
  return n;
}

// 判断字符串是否是回文
int isPalindromeStr(char s[]) {
  int result = 1;
  for(int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    if(s[i] != s[j]) {
      result = 0;
      break;
    }
  }
  return result;
}

// 判断字符串是否是回文
int isPalindromeStr2(char s[]) {
  int i = 0, j = strlen(s) - 1;
  while( i < j) {
    if(s[i++] != s[j--]) {
      return 0;
    }
  }
  return 1;
}

// 一个汉字占两个字节
int main()
{
  // 字符数组 根据对象内分配数量
  // char a[] = {'h', 'e', 'l', 'l', 'o'};
  // 注意还包含一个 /0 标记结束
  // char b[10] = {"hello"};
  // 也可以省略 字符串
  // char c[10] = "hello";

  // char arr[100];
  // 字符串取地址 %s, 数组名及代表数据首地址
  // scanf("%s", arr);

  // 单字符 输入getchar 输出putchar
  /*
    字符串 输入gets(数组名)，可以录入空格否则只能scanf("%[^/n]")来录入空格
    输出puts(数组名)
  */

  // 字符串函数
  // char name[12] = "tree";
  // char name1[18] = "flower";
  // 连接  strcat(字符数组，字符串)
  // puts(strcat(name, name1));

  // 复制  strcpy(字符数组，字符串) 覆盖式的
  // puts(strcpy(name, name1));

  // 比较  strcmp(字符数组，字符串) ；大于 返回1；小于返回-1；等于返回0；对比的是ASCII码值；
  // OS下会返回运算结果，从第一个字符开始，不等就返回
  // printf("result: %d\n", strcmp(name,name1));

  // 长度  strlen(字符串数组) 不包括 /0
  // printf("arrLen: %ld\n", strlen(name));

  // 此处后面给的是ASCII码
  // char str[] = {1, 2, 3, 4, 97, 65, 'a'};

  // printf(" %d\n", str[5]);
  // printf(" %c\n", str[5]);

  // printf(" %d\n", str[6]);
  // printf(" %c\n", str[6]);

  // char str1[] = "Hello";
  // char str2[] = "Hello";
  // str1、str2 代表的是首地址，绝不会相等。判定相等使用strcmp;
  // int result = str1 == str2;
  // printf(" str1 == str2 %d\n", result);

  char str[100];
  printf("请输入一个字符串 ");
  scanf("%s", str);

  int result = isPalindromeStr(str);

  if(result) {
    printf(" 字符串 %s 是回文 \n", str);
  } else {
    printf(" 字符串 %s 不是回文 \n", str);
  }

  return 0;
}