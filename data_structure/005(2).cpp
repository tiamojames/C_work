#include <iostream>

using namespace std;
#define maxnum 100

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
    plinklist l = (plinklist)malloc(sizeof(linklist));
    l->head = (pnode)malloc(sizeof(node));
    pnode p,q = l->head;
    for(int i=0; i<n; i++)
    {
        p = (pnode)malloc(sizeof(node));
        cin>>p->val;
        q->next = p;
        q = p;
        q->next = nullptr;
    }
    
    return l;
}

void intersection(plinklist la, plinklist lb)
{
    pnode p = la->head,q = lb->head->next;
    int num=0;
    while(p)
    {   
        num = 0;
        q = lb->head->next;
        while(q)//在b中搜索
        {
            if(p->next && q->val == p->next->val)
                {
                    num=1;
                    break;
                }
            q = q->next;
        }
        if(p->next && !num)//没有找到  删除
        {
            pnode temp;
            temp = p->next;
            p->next = temp->next;
            //free(temp);
            p = p->next;
        }
        else
            p = p->next;

    }

}


void intersection2(plinklist la, plinklist lb)
{
    pnode p = la->head,q = lb->head->next;
    int num;
    while(p)
    {   
        num=0;
        q = lb->head->next;
        while(q)
        {
            if(p->next && q->val == p->next->val)
                {
                    num=1;
                    break;
                }
            q = q->next;
        }
        if(p->next && num)//找到le1
        {
            pnode temp;
            temp = p->next;
            p->next = temp->next;
            free(temp);
            p = p->next;
        }
        else
            p = p->next;

    }

}


void output(plinklist la)
{
    pnode p = la->head->next;
    while(p)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
}

int main()
{   int n1,n2,n3;
    cin>>n1>>n2>>n3;
    plinklist la = create_linklist(n1), lb = create_linklist(n2), lc = create_linklist(n3);
    intersection(lb,lc);
    intersection2(la,lb);
    output(la);

    return 0;
}