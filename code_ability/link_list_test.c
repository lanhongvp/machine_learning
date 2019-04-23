#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node{
    int data;
    struct node *next;
}Node,*pNode;
//创建一个带头节点的空单链表
pNode CreateListHead(void){
    pNode L = (pNode)malloc(sizeof(Node));
    if(!L)
        exit(-1);
    L->next = NULL;
    return L;
}
//输出单链表
void DisLinkList(pNode L)
{
    pNode p = L->next;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}
//求单链表长度
int ListLength(pNode L){
    pNode p = L->next;
    int k = 0;
    while(p){
        p = p->next;
        k++;
    }
    return k;
}
//获取元素
int GetElem(pNode L,int pos, int *e){
    pNode p = L->next;
    int i = 1;
    while(p && i<pos){
        p=p->next;
        ++i;
    }
    if(!p || i>pos){
        return 0;
    }
    *e = p->data;
    return 1;
}
//插入元素
int ListInsert(pNode L,int pos, int e){
    pNode p = L;
    pNode pNew;
    int i = 1;
    while(p&& i<pos){
        p = p->next;
        ++i;
    }
    if(!p || i<pos)
        return 0;
    pNew = (pNode)malloc(sizeof(Node));
    pNew->data = e;
    pNew->next = p->next;
    p->next =pNew;
    return 1;
}
//删除元素
int ListDelete(pNode L,int pos ,int *e){
    pNode p = L;
    pNode q;
    int i=1;
    while(p->next && i<pos)
    {
        p = p->next;
        ++i;
    }
    if(!(p->next) || i>pos)
        return 0;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return 1;

}
int main(void){
    pNode L;
    int e,f,g;
    int pos =7;
    L = CreateListHead();
    ListInsert(L,1,1);
    ListInsert(L,2,2);
    ListInsert(L,3,3);
    ListInsert(L,4,4);
    ListInsert(L,5,5);
    ListInsert(L,6,6);
    ListInsert(L,7,7);
    printf("输出单链表\n");
    DisLinkList(L);
    printf("\n获取第三个元素\n");
    GetElem(L,3,&e);
    printf("%d\n",e);
    printf("删除第四个元素\n");
    ListDelete(L,4,&f);
    printf("%d\n",f);
    g=ListLength(L);
    printf("单链表目前长度为%d\n",g);
    return 0;
}
