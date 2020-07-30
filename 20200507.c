#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *a = NULL;
    char *b = NULL;
    a = (char *)malloc(10 * sizeof(char));
    strcpy(a, "www.lm."); //将字符串“www.lm.”赋值给a
    b = (char *)malloc(10 * sizeof(char));
    strcpy(b, "edu.cn");    //将字符串“edu.cn”赋值给b
    int lentha = strlen(a); //字符串a的长度
    int lenthb = strlen(b); //字符串b的长度
    //将字符串a和b合并，放到a里，假如a的长度不够，realloc进行动态申请
    if (lentha)
    {
        a = (char *)realloc(a, (lentha + lenthb + 1) * sizeof(char));
    }
    //合并一起
    for (int i = lentha; i < lentha + lenthb; i++)
    {
        a[i] = b[i - lentha];
    }
    //为了保证不出错，所以尾部再加入一个\0
    a[lentha + lenthb] = '\0';
    printf("%s\n", a);
    //释放空间
    free(a);
    free(b);
    return 0;
}