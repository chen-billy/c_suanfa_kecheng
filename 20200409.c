#include <stdio.h>
#include <malloc.h>
#define MaxSize 3 // 堆栈元素的最大个数
typedef struct SNode *Stack;
struct SNode
{
    int Data[MaxSize]; // 存储堆栈元素
    int Top;           // 记录栈顶元素下标
};
//初始化栈
Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Top = -1;
    return S;
}
//判断是否满
int IsFull(Stack S)
{
    return (S->Top == MaxSize - 1);
}
//判断是否空
int IsEmpty(Stack S)
{
    return (S->Top == -1);
}
//入栈
int Push(Stack S, int X)
{
    if (IsFull(S))
    {
        printf("栈已经满");
        return 0;
    }
    else
    {
        S->Top++; // 栈顶自增
        S->Data[S->Top] = X;
        return 1;
    }
}
// 出栈
int Pop(Stack S)
{
    if (IsEmpty(S))
    {
        printf("栈已空");
        return 0;
    }
    else
    {
        int val = S->Data[S->Top];
        S->Top--;
        return val;
    }
}
int main()
{
    Stack S;
    S = CreateStack();
    Push(S, 5);
    printf("%d入栈\n", S->Data[S->Top]);
    Push(S, 7);
    printf("%d入栈\n", S->Data[S->Top]);
    Push(S, 9);
    printf("%d入栈\n", S->Data[S->Top]);
    printf("%d出栈\n", Pop(S));
    printf("%d出栈\n", Pop(S));
    printf("%d出栈\n", Pop(S));
    printf("%d出栈\n", Pop(S));
}