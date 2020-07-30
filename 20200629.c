#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} BitTree;
void insert(BitTree *bt, int key)
{
    BitTree *parent;
    BitTree *head = bt;
    BitTree *p = (BitTree *)malloc(sizeof(BitTree));
    p->data = key;
    p->lchild = p->rchild = NULL;
    while (head)
    {
        parent = head;
        if (key < head->data)
            head = head->lchild;
        else
            head = head->rchild;
    }
    if (key < parent->data)
        parent->lchild = p;
    else
        parent->rchild = p;
}
BitTree *create(BitTree *bt, int data[], int n)
{
    bt = (BitTree *)malloc(sizeof(BitTree));
    bt->data = data[0];
    bt->lchild = bt->rchild = NULL;
    for (int i = 1; i < n; i++)
    {
        insert(bt, data[i]);
    }
    return bt;
}
void inOrder(BitTree *bt)
{
    if (bt)
    {
        inOrder(bt->lchild);
        printf("%d ", bt->data);
        inOrder(bt->rchild);
    }
}
void preOrder(BitTree *bt)
{
    if (bt)
    {
        printf("%d ", bt->data);
        preOrder(bt->lchild);
        preOrder(bt->rchild);
    }
}
void houxu(BitTree *bt)
{
    if (bt)
    {
        houxu(bt->lchild);
        houxu(bt->rchild);
        printf("%d ", bt->data);
    }
}
void delete (BitTree *bt, int key)
{
    BitTree *L, *LL;
    BitTree *p = bt;
    BitTree *parent = bt;
    int child = 0;
    if (!bt)
        return;
    while (p)
    {
        if (p->data == key)
        {
            if (!p->lchild && !p->rchild)
            {
                if (p == bt)
                    free(p);
                else if (child == 0)
                {
                    parent->lchild = NULL;
                    free(p);
                }
                else
                {
                    parent->rchild = NULL;
                    free(p);
                }
            }
            else if (!p->lchild)
            {
                if (child == 0)
                    parent->lchild = p->rchild;
                else
                    parent->rchild = p->rchild;
                free(p);
            }
            else if (!p->rchild)
            {
                if (child == 0)
                    parent->lchild = p->lchild;
                else
                    parent->rchild = p->lchild;
                free(p);
            }
            else
            {
                LL = p;
                L = p->rchild;
                if (L->lchild)
                {
                    LL = L;
                    L = L->lchild;
                    p->data = L->data;
                    LL->lchild = L->lchild;
                    for (; L->lchild; L = L->lchild)
                        L->lchild = p->lchild;
                    p->lchild = NULL;
                }
                else
                {
                    p->data = L->data;
                    LL->rchild = L->rchild;
                }
            }
            p = NULL;
        }
        else if (key < p->data)
        {
            child = 0;
            parent = p;
            p = parent->lchild;
        }
        else
        {
            child = 1;
            parent = p;
            p = p->rchild;
        }
    }
}



int main()
{
    int a[1000], N;
    printf("请输入成绩的个数：");
    scanf("%d", &N);
    printf("输入成绩：");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }
    BitTree *bt = NULL;
    bt = create(bt, a, N);
    printf("1、前序遍历输出：");
    preOrder(bt);
    printf("\n");
    printf("后序遍历输出：");
    houxu(bt);
    printf("\n");
    printf("2、从小到大排序：");
    inOrder(bt);
    printf("\n");
    printf("3、成绩最高为：");

    printf("   成绩最低为：");

    printf("\n");
    delete (bt, 66);
    printf("4、删除成绩66，输出二叉树：");
    inOrder(bt);
    printf("\n");
    delete (bt, 90);
    printf("5、删除90，输出二叉树：");
    inOrder(bt);
    printf("\n");
    delete (bt, 75);
    printf("6、删除成绩75，输出二叉树：");
    inOrder(bt);
    printf("\n");
}
