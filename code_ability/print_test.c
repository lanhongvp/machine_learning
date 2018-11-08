#include <stdio.h>

void PrintN(int n);
void PrintN1(int n);

void PrintN(int N)
{
    if(N){
        PrintN(N-1);
        printf("%d\n",N);
    }
    return;
}


void PrintN1(int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%d\n",i);
    }
    return;
}

int main()
{
    // PrintN(100000);
    PrintN1(100000);
}