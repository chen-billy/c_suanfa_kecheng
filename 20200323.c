#include <stdio.h>
#include <malloc.h>
typedef int ElementType; // ElementType 可定义为任意类型
typedef struct LNode *List;
struct LNode
{
    ElementType Data; //数据域
    List Next;        // 指针域下一个链表的地址
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
    List p = L;  //p指向头指针
    int len = 1; //长度从1开始
    while (p->Next != NULL)
    { //如果指向下一个指针不为空
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
        return p;
    else
        return NULL;
}
//按值查找
List Find(ElementType X, List L)
{
    List p = L;
    while (p != NULL && p->Data != X)
        p = p->Next;
    return p;
}

//插入
List Insert(ElementType X, int i, List L)
{
    List p, s;
    if (i == 1)
    { //新节点插入在表头
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = L;
        return s;
    }
    p = FindKth(i - 1, L); //找到第i-1个结点
    if (!p)
    { //第i-1个结点不存在
        printf("结点错误！");
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
/*删除结点
1.用指针p指向链表的第i-1个结点
2.用指针s指向要被删除的第i个结点
3.用p->Next=s->Next,p指针指向s的后面
4.free(s),释放空间
*/
List Delete(int i, List L)
{
    List p, s;
    if (i == 1) //如果删除第一个节点
    {
        s = L;
        if (L) //如果不为空
        {
            L = L->Next;
        }
        else
        {
            return NULL;
        }
        free(s); //释放被被删除的节点
        return L;
    }
    p = FindKth(i - 1, L); //查找第i-1个节点
    if (!p || !(p->Next))  //第i-1个或第i个节点不存在
    {
        printf("结点错误");
        return NULL;
    }
    else
    {
        s = p->Next;       //s指向第i个结点
        p->Next = s->Next; //删除结点
        free(s);           //释放空间
        return L;
    }
}

// 输出链表元素
void Print(List L)
{
    List t;
    int flag = 1;
    printf("当前链表为：");
    for (t = L; t; t = t->Next)
    {
        printf("%d  ", t->Data);
        flag = 0;
    }
    if (flag)
        printf("NULL");
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
    printf("当前链表的长度：%d\n", Length(L));
    L = Insert(99, 3, L);
    Print(L);
    printf("当前链表的长度：%d\n", Length(L));
    L = Insert(100, 1, L);
    Print(L);
    // L = Insert(120, 0, L);
    // Print(L);
    printf("当前链表的长度：%d\n", Length(L));
    printf("链表中第2个节点的值是%d\n", FindKth(2, L)->Data);
    printf("查找900是否在链表中：");
    if (Find(900, L))
    {
        printf("是！\n");
    }
    else
    {
        printf("否！\n");
    }
    L = Delete(1, L);
    Print(L);
    L = Delete(3, L);// 注意二次删除的情况
    printf("删除后是：\n");
    Print(L);
}