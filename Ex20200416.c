#include <stdio.h>
#include <malloc.h>
typedef struct SNode *Stack;
struct SNode
{
    int Data;
    Stack Next;
};
// 初始化
Stack CreateStack()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}
// 判断是否为空
int IsEmpty(Stack S)
{
    return (S->Next == NULL);
}
// 入栈
void Push(Stack S, int item)
{
    Stack tmp;
    tmp = (Stack)malloc(sizeof(struct SNode));
    tmp->Data = item;
    // 链栈栈顶元素是链表头结点，新入栈的链表在栈顶元素后面
    tmp->Next = S->Next;
    S->Next = tmp;
}
//出栈
int Pop(Stack S)
{
    Stack First; // 栈顶指针
    int V;       //用来存储出栈的Data
    if (IsEmpty(S))
    {
        printf("链栈已空！");
        return 0;
    }
    else
    {
        First = S->Next;
        S->Next = First->Next;
        V = First->Data;
        free(First);
        return V;
    }
}
//十进制转换八进制
void Conversion(int n)
{
    int e;
    static S;
    S = CreateStack(S);
    while (n)
    {
        Push(S, (n % 8));
        n /= 8;
    }
    printf("转换成八进制为:");
    while (!IsEmpty(S))
    {
        e = Pop(S);
        printf("%d", e);
    }
}
int main()
{
    int n;
    printf("请输入一个十进制数：");
    scanf("%d", &n);
    Conversion(n);
    return 0;
}