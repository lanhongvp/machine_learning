#include<stdio.h>
#include<stdlib.h>

typedef struct LNode *List;
typedef int ElementType

struct LNode
{
    ElementType Data;
    List Next;
}

int Length(List PtrL);
List FindKth(int K,List PtrL);
List Insert(ElementType X,int i,List PtrL);
List Delete(ElementType X,List PtrL);

int Length(List PtrL)
{
    List p = PtrL;
    int j = 0;
    
    while(p)
    {
        p = p->Next;
        j++;   
    }
    return j;
}

List FindKth(int K,List PtrL)
{
    List p = PtrL;
    int i=1;
    while(p!=NULL&&i<K)
    {
        p = p->Next;
        i++;
    }
    if(i==K) return p;
    else return NULL;
}

List Insert(ElementType X,int i,List PtrL)
{
    List p,s;
    if(i==1)
    {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = PtrL;
        return s;
    }
    p = FindKth(i-1,PtrL);
    if(p==NULL)
    {
        printf("insert is illegal\n");
        return NULL;
    }else
    {
        s = (List)malloc(sizeof(struct LNode));
        S->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}

List Delete(int i,List PtrL)
{
    List p,s;
    if(i==1)
    {
        s = PtrL;
        if(PtrL!=NULL) PtrL=PtrL->Next;
        else return NULL;
        free(s);
        return PtrL;
    }
    p = FindKth(i-1,PtrL);
    if(p==NULL)
    {
        printf("The %d is not exist\n",i-1)
    }else if(p->Next==NULL)

}