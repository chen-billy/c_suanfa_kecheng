#include <stdio.h>
#include <malloc.h>
#define MAXSIZ 100
typedef struct LNode *List;
struct LNode
{
    int Data[MAXSIZ];
    int Last;
};
List L;
List MakeEempty()
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}
int insert(int X, int i, List L)
{
    if (L->Last == MAXSIZ - 1)
    {
        printf("表满！");
        return 0;
    }
    if (i < 0 || L->Last + 1 < i)
    {
        printf("位置不合法");
    }
    int j;
    for (j = L->Last; j >= i; j--)
    {
        L->Data[j + 1] = L->Data[j];
    }
    L->Data[i] = X;
    L->Last++;
    return 0;
}
int Length(List L)
{
    return L->Last + 1;
}
int sort(List L)
{
    int i, j, mex;
    for (i = 0; i < Length(L) - 1; i++)
    {
        for (j = i + 1; j < Length(L); j++)
        {
            if (L->Data[i] > L->Data[j])
            {
                mex = L->Data[j];
                L->Data[j] = L->Data[i];
                L->Data[i] = mex;
            }
        }
    }
    return 0;
}
int main()
{
    int i;
    L = MakeEempty();
    insert(-10, 0, L);
    printf("在线性表中L-Data[0]插入-10\n");
    insert(10, 0, L);
    printf("在线性表中L-Data[0]插入10\n");
    insert(-30, 0, L);
    printf("在线性表中L-Data[0]插入-30\n");
    insert(30, 0, L);
    printf("在线性表中L-Data[0]插入30\n");
    insert(-40, 0, L);
    printf("在线性表中L-Data[0]插入-40\n");
    insert(40, 0, L);
    printf("在线性表中L-Data[0]插入40\n");
    sort(L);
    printf("此时的线性表为：");
    for (i = 0; i < Length(L); i++)
    {
        printf("%d ", L->Data[i]);
    }
    return 0;
}