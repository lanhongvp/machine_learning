#include<stdio.h>
#include<stdlib.h>


#define True 1;
#define False 0;


typedef int position;
typedef int ElementType;
typedef struct sNode *Stack;

Stack CreateStack(int MaxSize);
_Bool isFull(Stack S);
_Bool Push(Stack S,ElementType X);
_Bool isEmpty(Stack S);
ElementType pop(Stack S);


struct sNode
{
    ElementType *Data;
    position Top;
    int MaxSize;
};


Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct sNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}


_Bool isFull(Stack S)
{
    return(S->Top == S->MaxSize-1);
}


_Bool Push(Stack S,ElementType X)
{
    
    if (isFull(S)) 
    {
        printf("The stack is full");
        return False;   
    }
    
    else
    {
        S->Data[++(S->Top)] = X;
        return True;
    }  
}


_Bool isEmpty(Stack S)
{
    return(S->Top==-1);
}


ElementType pop(Stack S)
{
    if(isEmpty(S))
    {
        printf("The stack is empty");
        return False;
    }
    else
    {
        return(S->Data[(S->Top)--]);
    }
}


void DisStack(Stack S)
{
    Stack tmp_s = S;
    
    while(tmp_s->Top != -1)
    {
    printf("The stack %d\n",tmp_s->Data[(tmp_s->Top)]);
    tmp_s->Top--;    
    }
}


int main()
{
    Stack stack_test;
    int MaxSize = 4;
    stack_test = CreateStack(MaxSize);

    Push(stack_test,1);
    Push(stack_test,2);
    Push(stack_test,3);
    Push(stack_test,4);

    DisStack(stack_test);
    

    return 0;
}
