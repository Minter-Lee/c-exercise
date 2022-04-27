#include <stdio.h>

int main()
{
  // r 只读(文件必须存在) w 只写（不存在则新建，已存在则覆盖） a 追加 可读 追加文件尾部或新建
  // 即读又写 r+ （文件存在，若不存在，读不了） w+ a+ （不存在则新建）
  FILE *fp = fopen("lagogo", "w+");
  // 以下内容值3分
  if (fp == NULL)
  {
    printf("该文件不存在！ \n");
    return 0;
  }

  // fputc('A', fp);
  // // 此时因为写的原因，fp指向了文件尾
  // putchar(fgetc(fp));

  // printf("\n");

  // rewind(fp);
  // putchar(fgetc(fp));

  // //随机输入一个字符串写入文件，再读出输出到显示器上 键盘->内存->文件->显示器
  // puts("请输入一个字符串，以#号字符结束");
  // // 键盘->内存
  // char ch = getchar();
  // // 已#号为结束符，循环读入
  // while (ch != '#')
  // {
  //   fputc(ch, fp);
  //   ch = getchar();
  // }

  // printf("\n");
  // // 重置指针位置
  // rewind(fp);
  // // 读文件
  // ch = fgetc(fp);
  // // EOF 文件结束符
  // while (ch != EOF)
  // {
  //   // 从文件到显示器
  //   putchar(ch);
  //   ch = fgetc(fp);
  // }

  // 用字符串读写的方法实现
  // char str1[30], str2[30];

  // puts("请输入字符串：");
  // // 键盘到内存
  // gets(str1);
  // // 内存到文件
  // fputs(str1,fp);
  // // 指针位置重置
  // rewind(fp);
  // // 文件到内存， 读4个外加\0
  // fgets(str2, 5, fp);
  // // 内存到显示器
  // puts(str2);

  // 字符块内容的读写(二进制)
  // struct stu
  // {
  //   int num;
  //   char name[20];
  // } s1[2], s2[2];

  // // 键盘到内存
  // printf("请输入数据");
  // for (int i = 0; i < 2; i++)
  // {
  //   scanf("%d%s", &s1[i].num, s1[i].name);
  // }
  // // 内存s1到文件
  // fwrite(s1, sizeof(struct stu), 2, fp);
  // //
  // // 文件到内存s2
  // fread(s2, sizeof(struct stu), 2, fp);
  // // s2到显示器
  // for (int i = 0; i < 2; i++)
  // {
  //   printf("%d, %s, \n", s1[i].num, s1[i].name);
  // }

  fclose(fp);

  // FILE *fp2 = fopen("demo", "w+");
  // if (fp2 == NULL)
  // {
  //   printf("该文件不存在 \n");
  //   return 0;
  // }

  // // 格式化读写
  // int a;
  // char str[20];
  // printf("请输入一个整数和字符串：");
  // // 键盘到内存
  // scanf("%d%s", &a, str);
  // // 内存到文件
  // fprintf(fp2, "%d%s", a, str);
  // // 重置指针位置
  // rewind(fp2);
  // // 文件到内存
  // int a2;
  // char str2[20];
  // fscanf(fp2, "%s%d", str2, &a2);

  // printf("%s, %d\n", str, a);

  // fclose(fp2);

  FILE *fp3 = fopen("demo2", "w+");
  if (fp3 == NULL)
  {
    printf("该文件不存在！\n");
    return 0;
  }

  fprintf(fp3, "%s", "0123456789");
  fseek(fp3, -3, 2);
  // fread()
  putchar(fgetc(fp3));

  fclose(fp3);

  printf("\n");
}