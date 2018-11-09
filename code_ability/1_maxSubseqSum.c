#include<stdio.h>

int MaxSubseqSum1(int A[],int N);
int MaxSubseqSum2(int A[],int N);
int MaxSubseqSum3(int A[],int N);
int MaxSubseqSum4(int A[],int N);
int Max3(int A,int B,int C);
int DivideAndConquer(int List[],int left,int right);


int MaxSubseqSum1(int A[],int N)
{
    int ThisSum,MaxSum = 0;
    int i, j, k;
    for(i=0;i<N;i++)
    {
        ThisSum = 0;
        for(j=i;j<N;j++)
        {
            ThisSum += A[j];
            if(ThisSum>MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}


int Max3(int A,int B,int C)
{
    return A > B ? A > C ? A:C:B > C ? B:C;
}


int DivideAndConquer(int List[],int left,int right)
{
    int MaxLeftSum,MaxRightSum;
    int MaxLeftBorderSum,MaxRightBorderSum;

    int LeftBorderSum,RightBorderSum;
    int center,i;

    if(left == right)
    {
        if(List[left]>0) return List[left];
        else return 0;
    }

    center = (left + right) / 2;
    printf("center %d\n",center);
    MaxLeftSum = DivideAndConquer(List,left,center);
    // printf("list 1 %d\n",*List);
    printf("MaxLeftSum %d\n",MaxLeftSum);
    MaxRightSum = DivideAndConquer(List,center+1,right);
    // printf("list 2 %d\n",*List);
    printf("MaxRightSum %d\n",MaxRightSum);

    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for(i=center;i>=left;i--)
    {
        LeftBorderSum += List[i];
        if(LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    printf("MaxLeftBorderSum %d\n",MaxLeftBorderSum);

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for(i=center+1;i<=right;i++)
    {
        RightBorderSum += List[i];
        if(RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }
    printf("MaxRightBorderSum %d\n",MaxRightBorderSum);

    return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum);

}


int MaxSubseqSum3(int A[],int N)
{
    return DivideAndConquer(A,0,N-1);
}


int main()
{
    // int A[5];int N;
    int compare_list[4] = {1,2,3,4};
    int N = 4;
    int MaxSum1,MaxSum2,MaxSum3;
    int max_num;
    // int A,B,C;
    MaxSum1 = MaxSubseqSum1(compare_list,N);
    MaxSum2 = MaxSubseqSum3(compare_list,N);
    // A = 2;B = 3;C = 5;
    // max_num = Max3(A,B,C);
    // printf("max_num %d",max_num);
    printf("maxsum1 %d\n",MaxSum1);
    printf("maxsum2 %d\n",MaxSum2);

    return 0;
}
