#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

# define maxnum 100

typedef struct node
{
    int val;
    node *next;
}node,*pnode;

typedef struct linklist
{
    pnode head;
}linklist,*plinklist;

plinklist create_linklist(int n)
{
    plinklist pl = (plinklist)malloc(sizeof(linklist));
    pl->head = (pnode)malloc(sizeof(node));
    int n;
    cin>>n;
    pnode p,q = pl->head;
    for(int i=0; i<n; i++)
    {   
        p = (pnode)malloc(sizeof(node));
        cin>>p->val;
        q->next = p;
        q = p;//q = q->next;
    }
    p->next = nullptr;
    return pl;
}

void reverse(plinklist pllist)
{
    pnode p,q;//p保存下一个逆置节点，q保存当前逆置节点
    p = pllist->head->next;
    pllist->head->next = nullptr;
    while(p)
    {
        q = p;
        p = p->next;
        q->next = pllist->head->next;
        pllist->head->next = q;
    }
}

void output(plinklist pllist)                 
{
    pnode p = pllist->head->next;
    while(p)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
}


typedef struct seqlist
{
    int element[100];
    int length;
}seqlist;
//顺序表插入
typedef struct seqlist *pseqlist;//顺序表指针类型

// int reverse_seqlist(pseqlist palist)
// {
//     int i=0 ,j=palist->length-1;
//     while(i<j)
//     {
//         swap(palist->element[i],palist->element[j]);
//         i++,j--;
//     }
//     return true;
// }

int verse(pseqlist palist)
{
    int i=0,j=palist->length-1;
    while(i<j)
    {
        swap(palist->element[i],palist->element[j]);
        i++,j--;
    }
}

int main()
{   
    plinklist pllist = create_linklist();
    reverse(pllist);
    output(pllist);
    return 0;
}