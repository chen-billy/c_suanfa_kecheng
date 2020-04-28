#include <stdio.h>
#include <string.h>
typedef struct stack
{
    char data[10000];
    int top;
} stack;
void caculate1(char *data)
{
    stack temp = {{0}, -1};
    int size = strlen(data);
    for (int i = 0; i < size; ++i)
    {
        //假如是左括号 将其入栈
        if (data[i] == '(' || data[i] == '{' || data[i] == '[' || data[i] == '<')
        {
            temp.data[++temp.top] = data[i];
        }
        else
        {
            //如果不是  就将其与栈顶元素比较  不匹配则出错  匹配就出栈
            if ((data[i] == ')' && temp.data[temp.top] == '(') || (data[i] == '}' && temp.data[temp.top] == '{') ||
                (data[i] == ']' && temp.data[temp.top] == '[') || (data[i] == '>' && temp.data[temp.top] == '<'))
            {
                temp.top--;
            }
            else
            {
                printf("no\n");
                return;
            }
        }
    }
    if (temp.top == -1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}
int main()
{
    for (int i = 0; i < 6; ++i)
    {
        char data[10000];
        gets(data);
        caculate1(data);
    }
    return 0;
}