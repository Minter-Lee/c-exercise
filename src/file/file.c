#include <stdio.h>

int main() {
  FILE *fp = fopen("lagogo", "w");
  // 以下内容值3分
  if(fp == NULL){
    printf("该文件不存在！ \n");
    return 0;
  }else {
    printf("打开成功！\n");
  }

  fclose(fp);

}