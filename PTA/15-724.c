#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data; /* 存储结点数据 */
    PtrToNode Next;   /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Reverse(List L);

List Read()
{
    int d;
    scanf("%d", &d);
    if (!d)
        return NULL;
    List head, p;
    p = (List)malloc(sizeof(ElementType));
    p->Data = d;
    p->Next = NULL;
    head = p;
    scanf("%d", &d);
    while (d)
    {
        List q = (List)malloc(sizeof(ElementType));
        q->Data = d;
        q->Next = NULL;
        p->Next = q;
        p = q;
        scanf("%d", &d);
    }
    return head;
}

List Print(List X)
{
    List p;
    p = X;
    while (p)
    {
        printf("%d\n", p->Data);
        p = p->Next;
    }
}

List Reverse(List L)
{
    if (!L)
    {
        return NULL;
    }
    if (!(L->Next))
        return L;
    if (!(L->Next->Next))
    {
        List end = L->Next;
        L->Next->Next = L;
        L->Next = NULL;
        return end;
    }
    List p, q, r;
    p = L;
    q = L->Next;
    r = L->Next->Next;
    p->Next = NULL;
    q->Next = p;
    List ans = Reverse(r);
    r->Next = q;
    return ans;
}

int main()
{
    List test = Read();
    Print(test);
    List x = Reverse(test);
    Print(x);
}