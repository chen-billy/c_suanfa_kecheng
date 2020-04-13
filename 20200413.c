#include <stdio.h>
#include <malloc.h>SN
typedef struct SNode *Stack;
struct SNode
{
    int Data;   //数据域
    Stack Next; //指针域
};
//链栈初始化
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
int Push(Stack S, int item)
{
    Stack tem; //指向我新插入结点的指针
    tem = (Stack)malloc(sizeof(struct SNode));
    tem->Data = item; //将元素放入数据域
    tem->Next = S->Next;
    S->Next = tem;
}
int main()
{
    Stack S;
    S = CreateStack();
    Push(S, 5);
    printf("%d入栈\n", S->Next->Data);
    Push(S, 7);
    printf("%d入栈\n", S->Next->Data);
    Push(S, 10);
    printf("%d入栈\n", S->Next->Data);
    return 0;
}