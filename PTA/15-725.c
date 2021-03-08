#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};


List MakeEmpty()
{
    List X = (List)malloc(sizeof(struct LNode));
    X->Last = -1;
    return X;
}

Position Find(List L, ElementType X)
{
    for (int i = 0; i <= L->Last; ++i)
    {
        if (L->Data[i] == X)
        {
            return i;
        }
    }
    return -1;
}

bool Insert(List L, ElementType X, Position P)
{
    if (L->Last == -1)
    {
        L->Data[P] = X;
        L->Last++;
        return true;
    }
    if (L->Last + 1 == MAXSIZE)
    {
        printf("FULL");
        return false;
    }
    if (P > L->Last)
    {
        printf("ILLEGAL POSITION");
        return false;
    }
    for (int i = L->Last; i >= P; --i)
    {
        L->Data[i + 1] = L->Data[i];
    }
    L->Data[P] = X;
    L->Last++;
    return true;
}

bool Delete(List L, Position P)
{
    if (P > L->Last || P < 0)
    {
        printf("POSITION %d EMPTY", P);
        return false;
    }
    for (int i = P; i <= L->Last; ++i)
    {
        L->Data[i] = L->Data[i + 1];
    }
    L->Last--;
}

void Print(List M)
{
    printf("%d\n", M->Last);
    for (int i = 0; i <= M->Last; ++i)
    {
        printf("%d ", M->Data[i]);
    }List MakeEmpty()
{
    List X = (List)malloc(sizeof(struct LNode));
    X->Last = -1;
    return X;
}

Position Find(List L, ElementType X)
{
    for (int i = 0; i <= L->Last; ++i)
    {
        if (L->Data[i] == X)
        {
            return i;
        }
    }
    return -1;
}

bool Insert(List L, ElementType X, Position P)
{
    if (L->Last == -1)
    {
        L->Data[P] = X;
        L->Last++;
        return true;
    }
    if (L->Last + 1 == MAXSIZE)
    {
        printf("FULL");
        return false;
    }
    if (P > L->Last)
    {
        printf("ILLEGAL POSITION");
        return false;
    }
    for (int i = L->Last; i >= P; --i)
    {
        L->Data[i + 1] = L->Data[i];
    }
    L->Data[P] = X;
    L->Last++;
    return true;
}

bool Delete(List L, Position P)
{
    if (P > L->Last || P < 0)
    {
        printf("POSITION %d EMPTY", P);
        return false;
    }
    for (int i = P; i <= L->Last; ++i)
    {
        L->Data[i] = L->Data[i + 1];
    }
    L->Last--;
}
    printf("\n");
}

int main()
{
    List L;
    L = MakeEmpty();
    
    return 0;
}