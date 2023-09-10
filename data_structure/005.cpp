#include <iostream>

using namespace std;
#define maxnum 100
#define false 0
#define true 1

typedef struct node
{
    int info;
    node* next;
}node,*pnode;

typedef struct linklist
{
    pnode head;
}linklist,*plinklist;

pnode delete_link(plinklist pllist,int x)
{
    pnode p,q;
    p=pllist->head;
    //寻找元素x
    while(p->next!=NULL && p->next->info!=x)
    {
        p=p->next;
    }
    if(p->next==NULL)
    cout<<"not exist"<<endl;
    else
    {
        q=p->next;
        p->next=q->next;
        free(q);//释放被删除元素的节点空间
        return p;
    }
}
int locate_link(plinklist pllist,int x)//找到了返回1，否则0；
{
    pnode p;
    p = pllist->head->next; //第一个节点
    while(p!=NULL)
    {   
        if(p->info==x)
            return 1;//
        p=p->next;
        
    }
    return 0;
}
int retrieve_link(pnode p)
{
    return p->info;
}
plinklist create_null_list()//创建带头结点的空链表
{
    plinklist list;
    pnode p;
    list = (plinklist)malloc(sizeof(linklist));
    if(list!=NULL)
    {
        p = (pnode)malloc(sizeof(node));
        if(p!=NULL)
        {
            list->head=p;
            p->next=NULL;
        }
        else
        {
            cout<<"out of space"<<endl;
            list->head=NULL;
        }

    }
    else
        cout<<"out of space"<<endl;
    return list;
}
pnode find_link(plinklist pllist,int i)//返回第i个节点的位置
{
    pnode p;
    int j;
    if(i<1)
    {
        return NULL;
    }
    p = pllist->head;
    for(j=0;j<i;j++)
    {
        p=p->next;
        if(p==NULL)
        return NULL;
    }
    return p;
}
void intersection(plinklist la,plinklist lb)
{ 
    pnode p,q;
    int x,k;
    p=la->head->next;//第一个节点
    q=lb->head->next;
    while(p!=NULL)
    {   
        x=p->info;
        k=locate_link(lb,x);
        if(!k)
        {
            p=delete_link(la,x);
            p=p->next;
        }
        else
            p=p->next;
    }
}
void ans(plinklist la,plinklist lb)
{ 
    pnode p,q;
    int x,k;
    p=la->head->next;//第一个节点
    q=lb->head->next;
    while(p!=NULL)
    {   
        x=p->info;
        k=locate_link(lb,x);
        if(k)
        {
            p=delete_link(la,x);
            p=p->next;
        }
        else
            p=p->next;
    }
}
void input(plinklist pllist,int length)
{
    pnode q;
    q = pllist->head;
    for(int i=0; i<length; i++)
    {   pnode p = (pnode)malloc(sizeof(node));
        cin>>p->info;
        q->next=p;
        q=p;
    }
    q->next=NULL;
}
void output(plinklist pllist)
{
    pnode q= pllist->head;
    while(q->next!=NULL)
    {
        cout<<q->next->info<<" ";
        q=q->next;
    }
}
int main()
{   plinklist la=create_null_list(),lb=create_null_list(),lc=create_null_list();
    int na,nb,nc;
    cin>>na>>nb>>nc;
    input(la,na),input(lb,nb),input(lc,nc);
    intersection(lb,lc);
    ans(la,lb);
    output(la);
    return 0;
}