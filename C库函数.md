# C �⺯�� 
## һ����������ת������
### 1. atoi()
- ���ܣ�C �⺯�� int atoi(const char *str) �Ѳ��� str ��ָ����ַ���ת��Ϊһ������������Ϊ int �ͣ���
- ������int atoi(const char *str)
- ��Σ�str -- Ҫת��Ϊ�������ַ�����
- ����ֵ���ú�������ת����ĳ����������û��ִ����Ч��ת�����򷵻��㡣
- ʵ����
```c
#include<stdio.h>
#include<stdlib.h> //�⺯����ͷ�ļ�
void main()
{
    char *str = "2019-12-31";
    int year = atoi(str);  //ֻ����ȡ�ַ�������ʼ��ַ�����֣����������ּ�ֹͣ������
    int month = atoi(str+5);
    int day = atoi(str+8);
    printf("%d %d %d\n",year,month,day);//2019 12 31
}
```
## 2. atof()
- double atof(const char *str)
- �Ѳ��� str ��ָ����ַ���ת��Ϊһ��������������Ϊ double �ͣ���
## 3. atol()
- long int atol(const char *str)
- �Ѳ��� str ��ָ����ַ���ת��Ϊһ��������������Ϊ long int �ͣ���
- 

