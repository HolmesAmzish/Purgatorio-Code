#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define Maxsize 50
typedef struct
{
    int data[Maxsize];
    int length;
} SqList;
void InitList(SqList *L)
{
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}
void CreatList(SqList *L, int a[], int n)
{
    int i = 0, k = 0;
    while (i < n)
    {
        L->data[k] = a[i];
        k++;
        i++;
    }
    L->length = k;
}
void display(SqList *L) {
    int t;
    for (int i = 0; i < L->length - 1; i++) 
    {
        for (int j = 0; j < L->length - i - 1; j++) 
        {
            if (L->data[j] > L->data[j + 1]) 
            {
                t = L->data[j];
                L->data[j] = L->data[j + 1];
                L->data[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

bool ListInsert(SqList *L, int e) {
    if (L->length == Maxsize)
    {
        return false;
    }
    int i = 0, j;
    while (i < L->length && L->data[i] < e)
    {
        i++;
    }
    for (j = L->length; j > i; j++)
    {
        L->data[j] = L->data[j - 1];
    }
    L->data[i] = e;
    L->length++;
    return true;
}
void deleteelem(SqList *L, int x)
{
    int k = 0;
    int i;
    for (i = 0; i < L->length; i++)
    {
        if (L->data[i] != x)
        {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}
void hebing(SqList *L1, SqList *L2, SqList *L3)
{
    int i = 0, j = 0;
    while (i < L1->length)
    {
        L3->data[i] = L1->data[i];
        i++;
    }
    while (j < L2->length)
    {
        L3->data[i] = L2->data[j];
        j++;
        i++;
    }
    L3->length = i;
}

void deleterange(SqList *L, int s, int t) {
    if (s >= t || s < 0 || t > L->length) {
        printf("输入错误\n");
    }
    int i = 0, k = 0;
    while (i < L->length) {
        if (s <= L->data[i] && L->data[i] <= t) {
            // 跳过待删除的元素
            i++;
        } else {
            // 保留非删除区间的元素
            L->data[k++] = L->data[i];
            i++;
        }
    }
    L->length = k;
}

int main()
{
    SqList L1, L2, L3;
    InitList(&L1);
    InitList(&L2);
    InitList(&L3);
    int a[100], b[100];
    int x1, x2, length1, length2, e;
    while (1)
    {
        scanf("%d", &x1);
        if (x1 != -1)
        {
            a[length1] = x1;
            length1++;
        }
        else
            break;
    }
    CreatList(&L1, a, length1);
    scanf("%d", &e);
    while (1)
    {
        scanf("%d", &x2);
        if (x2 != -1)
        {
            b[length2] = x2;
            length2++;
        }
        else
            break;
    }
    CreatList(&L2, b, length2);
    int s, t;
    scanf("%d %d", &s, &t);
    display(&L1);
    deleteelem(&L1, e);
    hebing(&L1, &L2, &L3);
    display(&L3);
    deleterange(&L3, s, t);
    display(&L3);
    getchar();
    return 0;
}

/*
1 3 5 7 9 2 3 -1
3
3 5 6 -1
1 3
*/