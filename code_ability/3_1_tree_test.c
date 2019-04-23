#include <stdio.h>


typedef -1 NotFound;

int SequentialSearch(List Tb1,ElementType k)
{
    int i;
    Tb1->Element[0] = K;
    for(i = Tb1->Length;Tb1->Element[i]!=K;i--);
    return i;
}


int binarySearch(StaticTable *Tb1,ElementType k)
{
    int left,right,mid,NoFound=-1;

    left = 1;
    right = Tb1->Length;
    
    while(left<=right)
    {
        mid = (left+right)/2;
        if(k<Tb1->Element[mid]) right = mid-1;
        else if (k>Tb1->Element[mid]) left = mid+1;
        else return mid;
    }
    return NotFound;
}