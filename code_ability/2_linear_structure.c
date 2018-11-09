#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
typedef int ElementType;
// #define ElementType int

typedef struct LNode *List;

struct LNode
{
    ElementType Data[MAXSIZE];
    int Last;
};

struct LNode L;
List PtrL;

List MakeEmpty();
int Find(ElementType X,List PtrL);
void Insert(ElementType X,int i, List PtrL);
// List Insert(ElementType X,int i, List PtrL);
void Delete(ElementType X,int i,List PtrL);
// List Delete(int i,List PtrL);
int Length(List PtrL);
List FindKth(int K,List PtrL);

List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}

int Find(ElementType X,List PtrL)
{
    int i = 0;
    while(i<=PtrL->Last && PtrL->Data[i]!= X)
    i++;
    if(i>PtrL->Last) return -1;   
    else
        return i;   
}


void Insert(ElementType X,int i,List PtrL)
{
    int j;

    if(PtrL->Last==MAXSIZE-1)
    {
        printf("The list is full");
        return;
    }

    if(i<1 || i >PtrL->Last+2)
    {
        printf("The insert is illegal");
        return;
    }

    for (j=PtrL->Last;j>i-1;j--)
    {
        PtrL->Data[j+1] = PtrL->Data[j];
    }
    PtrL->Data[i-1]=X;
    PtrL->Last++;
    return;
}


void Delete(ElementType X,int i,List PtrL)
{
    int j;
    if(i<1||i>PtrL->Last+1)
    {
        printf("This element didn't exist");
        return;
    }
    for(j=i;j<PtrL->Last;j++)
    {
        PtrL->Data[j-1] = PtrL->Data[j];
    }
    PtrL->Last--;
    return;
}


int main()
{
    int x = 5;int i = 1;
    int findFlag;
    List PtrL;
    // PtrL->Last = NULL;
    PtrL = MakeEmpty();
    Insert(x,i,PtrL);
    // int tmp_list[MAXSIZE] = {1,2,3,4,5};
    // PtrL->Data[MAXSIZE] = 1;
    // PtrL->Last = Data[MAXSIZE];
    printf("test list %d\n",*(PtrL->Data));

    findFlag = Find(x,PtrL);
    printf("Find this element or not %d\n",findFlag);
    return 0;
}
