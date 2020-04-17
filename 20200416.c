#include <stdio.h>
#include <malloc.h>
typedef int ElementType;
typedef struct SNode *Stack;
struct SNode
{
    ElementType Data;
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
void Push(Stack S, ElementType item)
{
    Stack tmp;
    tmp = (Stack)malloc(sizeof(struct SNode));
    tmp->Data = item;
    // 链栈栈顶元素是链表头结点，新入栈的链表在栈顶元素后面
    tmp->Next = S->Next;
    S->Next = tmp;
}
//出栈
ElementType Pop(Stack S)
{
    Stack First;   // 栈顶指针
    ElementType V; //用来存储出栈的Data
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
    printf("%d出栈\n", Pop(S));
    printf("%d出栈\n", Pop(S));
    printf("%d出栈\n", Pop(S));
    printf("%d出栈\n", Pop(S));
    return 0;
}