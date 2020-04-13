#include <stdio.h>
#include <malloc.h>
typedef int ElementType; //ElementType 可定义为任意类型
typedef struct LNode *List;
struct LNode
{
    ElementType Data; //数据域
    List Next;        //指针域下一个链表的地址
};
List L; //头节点指针
//初始化链表
List MakeEmpty()
{
    List L = (List)malloc(sizeof(struct LNode)); //分配一个动态空间，L指向空间的首地址
    L = NULL;                                    //头节点为空
    return L;
}
//求链表的长度
int Length(List L)
{
    List p = L;             //p指向头指针
    int len = 0;            //长度从0开始
    while (p->Next != NULL) //如果指向下一个指针不为空
    {
        p = p->Next;
        len++;
    }
    return len;
}
//按序查找
List FindKth(int K, List L)
{
    List p = L;
    int i = 1;
    while (p->Next != NULL && i < K)
    {
        p = p->Next;
        i++;
    }
    if (i == K) //找到了
    {
        return p;
    }
    else
    {
        return NULL;
    }
}
//插入
List Insert(ElementType X, int i, List L)
{
    List p, s;
    if (i == 1) //新节点插入在表头
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = L;
        return s;
    }
    p = FindKth(i - 1, L); //找到第i-1个节点
    if (!p)
    {
        printf("节点错误");
        return NULL;
    }
    else
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return L;
    }
}
//输出链表元素
void Print(List L)
{
    List t;
    int flag = 1;
    printf("当前链表为：");
    for (t = L; t; t = t->Next)
    {
        printf("%d ", t->Data);
        flag = 0;
    }
    if (flag)
    {
        printf("NULL");
    }
    printf("\n");
}
int main()
{
    L = MakeEmpty(); //先初始化
    Print(L);
    L = Insert(25, 1, L);
    L = Insert(33, 2, L);
    L = Insert(77, 3, L);
    L = Insert(11, 4, L);
    Print(L);
    L = Insert(99, 3, L);
    Print(L);
    L = Insert(100, 1, L);
    Print(L);
    L = Insert(200, 0, L);
    Print(L);
}