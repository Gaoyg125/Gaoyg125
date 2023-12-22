# C 库函数 
## 一、数据类型转换函数
### 1. atoi()
- 功能：C 库函数 int atoi(const char *str) 把参数 str 所指向的字符串转换为一个整数（类型为 int 型）。
- 声明：int atoi(const char *str)
- 入参：str -- 要转换为整数的字符串。
- 返回值：该函数返回转换后的长整数，如果没有执行有效的转换，则返回零。
- 实例：
```c
#include<stdio.h>
#include<stdlib.h> //库函数的头文件
void main()
{
    char *str = "2019-12-31";
    int year = atoi(str);  //只会提取字符串的起始地址的数字，遇到非数字即停止并返回
    int month = atoi(str+5);
    int day = atoi(str+8);
    printf("%d %d %d\n",year,month,day);//2019 12 31
}
```
## 2. atof()
- double atof(const char *str)
- 把参数 str 所指向的字符串转换为一个浮点数（类型为 double 型）。
## 3. atol()
- long int atol(const char *str)
- 把参数 str 所指向的字符串转换为一个长整数（类型为 long int 型）。
- 

