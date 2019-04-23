#include<stdio.h>
#include<stdlib.h>


typedef struct LNode *List;
typedef int ElementType;


struct LNode
{
    ElementType Data;
    List Next;
};


struct LNode L;
List PtrL;


int Length(List PtrL);
List CreateListHead(void);
List FindKth(int K,List PtrL);
List Insert(ElementType X,int i,List PtrL);
List Insert_raw(ElementType X,int i,List PtrL);
List Delete(ElementType X,List PtrL);
void DisLinkList(List PtrL);


List CreateListHead()
{
    List L = (List)malloc(sizeof(List));
    if(!L) exit(-1);
    L->Next = NULL;
    return L;
}


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


List Insert_raw(ElementType X,int i,List PtrL)
{
    List p,s;
    if(i==1)
    {
        s = (List)malloc(sizeof(List));
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
        s = (List)malloc(sizeof(List));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}


List Insert(ElementType e,int pos,List PtrL)
{
    List p = PtrL;
    List pNew;
    int i = 1;
    while(p && i<pos)
    {
        p = p->Next;
        ++i;
    }
    if(!p || i<pos) return NULL;
    pNew = (List)malloc(sizeof(List));
    pNew->Data = e;
    pNew->Next = p->Next;
    p->Next = pNew;
    return p;
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
        printf("The %d is not exist\n",i-1);
        return NULL;
    }else if(p->Next==NULL)
    {
        printf("The %d is not exist\n",i);
        return NULL;
    }
    else
    {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return PtrL;
    }
}


void DisLinkList(List PtrL)
{
    List L = PtrL->Next;
    while(L)
    {
        printf("%d ",L->Data);
        L = L->Next;
    }
}


int main()
{
    List list_test;
    list_test = CreateListHead();
    Insert(1,1,list_test);
    Insert(4,2,list_test);
    Insert(2,3,list_test);
    Insert(5,4,list_test);
    Insert(6,5,list_test);
    printf("print link list\n");
    DisLinkList(list_test);
    return 0;
}


