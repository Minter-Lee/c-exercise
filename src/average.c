#include<stdio.h>

// 自定义函数实现求平均值

float average (int array[]) {
    double sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += array[i];
    }
    return sum / 10;
}

int main() {
    int arr[10];
    for(int i = 1; i <= 10; i++) {
        printf("请输入第%d个同学的成绩", i);
        scanf("%d", &arr[i-1]);
    }

    // 数组名就是首地址[arr]，
    // 地址传递：你变我也变
    // 方式1 数组做参数，方式2 指针做参数
    printf("平均值: %.2f \n", average(arr));

    return 0;
}