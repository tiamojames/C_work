#include <iostream>
#include <stack>
using namespace std;
#define maxnum 100

typedef struct doublenode
{
    char data;
    doublenode *pre, *next;
    int freq = 0;
}doublenode,*pdoublenode;


typedef struct dlinklist
{
    pdoublenode head,tail;
}dlinklist,*pdlinklist;

pdlinklist create_dlinklist(int length)
{
    pdlinklist pdlist = (pdlinklist)malloc(sizeof(dlinklist));
    pdlist->head = (pdoublenode)malloc(sizeof(doublenode));
    pdlist->tail = (pdoublenode)malloc(sizeof(doublenode));
    pdoublenode p,q = pdlist->head;
    for(int i=0; i<length; i++)
    {
        p = (pdoublenode)malloc(sizeof(doublenode));
        cin>>p->data;
        p->pre = q;
        q->next = p;
        q = p;
    }
    pdlist->tail = q;
    q->next = nullptr;
    return pdlist;

}


void locate(pdlinklist pllist, int n)
{   char c;
    for(int i=0; i<n; i++)
    {
        cin>>c;
        pdoublenode p = pllist->head->next; //第一个元素节点
        while(p)
        {
            if(p->data == c)
            {
                p->freq++;
                break;
            }
            else
                p = p->next;
        }
    }
    
}

void bubblesort(pdlinklist pllist, int n)
{
    pdoublenode p = pllist->head->next;
    while(n--)
    {
        while(p->next)
        {   if(p->freq < p->next->freq)
            {
                char c;//结点不动，仅交换数值
                int fre;
                c = p->data;
                fre = p->freq;
                p->data = p->next->data;
                p->freq = p->next->freq;
                p->next->data = c;
                p->next->freq = fre;
            }
            p = p->next;
        }
        p = pllist->head->next; //继续从头开始搜索比较
    }
}

void print(pdlinklist pllist)
{
    pdoublenode p = pllist->head->next;
    while(p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main()
{   
    stack <int> s;
    int n,n1;
    cin>>n>>n1;
    pdlinklist pllist = create_dlinklist(n);
    locate(pllist,n1);
    bubblesort(pllist,n);
    print(pllist);

    return 0;
}