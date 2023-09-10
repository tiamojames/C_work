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

/*void merge(plinklist la, plinklist lb)
{
    pnode pa = la->head,pb = lb->head->next;
    while(pa->next && pb)
    {   
        pnode qa = pa, qb = pb;
        if(pa->next && pa->next->val >= pb->val)
        {   
            qb = pb->next;
            pb->next = pa->next;
            pa->next = pb;
            //尾插法递增序列
            pb = qb;
        }
        else if(pa->next && pa->next->val < pb->val )
        {   
            pa = pa->next;
        }

    }
    if(!pa->next) //pa如果为空，说明剩下的pb元素均比pa大，直接接到后面
    {
        pa->next = pb;
    }
    
}*/

void merge(plinklist la, plinklist lb, plinklist lc)
{
    pnode pa = la->head->next,pb = lb->head->next, pc = lc->head;
    pnode temp;
    while(pa && pb)
    {   
        if(pa->val<=pb->val)
        {
            temp = pa;
            pa = pa->next;

            temp->next = pc->next;
            pc->next = temp;
        }
        else
        {
            temp = pb;
            pb = pb->next;

            temp->next = pc->next;
            pc->next = temp;
        }
    }  
    while(pa) //pa不为空说明pa还有剩余元素没有插入
    {
        temp = pa;
        pa = pa->next;

        temp->next = pc->next;
        pc->next = temp;
    }
    while(pb)
    {
        temp = pb;
        pb = pb->next;

        temp->next = pc->next;
        pc->next = temp;
    }

  
}

void output(plinklist la)
{
    pnode p=la->head->next;
    while(p)
    {
        cout<<p->val<<" ";
        p = p->next;
    }
}

int main()
{   int n1,n2;
    cin>>n1>>n2;
    plinklist la = create_linklist(n1), lb = create_linklist(n2);
    plinklist lc = (plinklist)malloc(sizeof(linklist));
    lc->head = (pnode)malloc(sizeof(node));
    lc->head->next = nullptr;
    merge(la,lb,lc);
    output(lc);

    return 0;
}