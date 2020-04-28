#include <stdio.h>
#include <malloc.h>
typedef int Etype;
typedef struct SNode *Stack;
struct SNode
{
    Etype Data;
    Stack Next;
};

Stack CreateStack();         // 初始化链栈
int IsEmpty(Stack S);        //判断链栈是否为空
void Push(Stack S, Etype X); //入栈
Etype Pop(Stack S);          // 出栈

//初始化
Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

//判断是否为空
int IsEmpty(Stack S)
{
    return (S->Next == NULL);
}

//入栈
void Push(Stack S, Etype X)
{
    Stack tmp;
    tmp = (Stack)malloc(sizeof(struct SNode));
    tmp->Data = X;
    tmp->Next = S->Next;
    S->Next = tmp;
}

//出栈
Etype Pop(Stack S)
{
    Stack Top; //栈顶指针
    Etype V;   //用来存储出栈的 Data
    if (IsEmpty(S))
    {
        printf("栈已经空！");
        return 0;
    }
    else
    {
        Top = S->Next;
        S->Next = Top->Next;
        V = Top->Data;
        return V;
    }
}

//进制转换
convert(Stack S)
{
    Etype N;
    printf("请输入一个十进制的整数:");
    scanf("%d", &N);
    while (N)
    {
        Push(S, N % 8);
        N = N / 8;
    }
    printf("八进制是:");
    while (!IsEmpty(S))
    {
        printf("%d", Pop(S));
    }
    printf("\n");
}
//测试
int main()
{
    Stack S;
    S = CreateStack();
    convert(S);
}