#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100      //栈的元素最大个数
typedef struct Snode *Stack;
struct Snode
{
    int Data[MAXSIZE]; //存储栈的元素
    int Top;                   //栈顶元素下标
};
//初始化栈
Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct Snode));
    S->Top = -1;
    return S;
}
//栈是否为满
int isFull(Stack S)
{
    return (S->Top == MAXSIZE - 1);
}
//栈是否为空
int isEmpty(Stack S)
{
    return (S->Top == -1);
}
//入栈
void Push(Stack S, int X)
{
    if (isFull(S))
    {
        printf("栈已经满了！");
        return;
    }
    else
    {
        S->Top++;            //栈顶自增
        S->Data[S->Top] = X; //放进元素
        return;
    }
}
int main()
{
    Stack S;
    S = CreateStack();
    Push(S, 5);
    printf("%d入栈\n", S->Data[S->Top]);
    Push(S,7);
    printf("%d入栈\n", S->Data[S->Top]);
    return 0;
}