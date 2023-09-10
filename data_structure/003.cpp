#include <iostream>

using namespace std;
#define maxnum 100

typedef struct seqlist
{
    int data[maxnum];
    int length;
}seqlist,*pseqlist;

pseqlist input(int n)
{
    pseqlist l = (pseqlist)malloc(sizeof(seqlist));
    for(int i=0; i<n; i++)
    {
        cin>>l->data[i];
    }
    l->length = n;
    return l;
}

void intersection(pseqlist la, pseqlist lb)//找交集
{   
    int tempa;
    for(int i=0; i<la->length; i++)
    {
        for(int j=0; j<lb->length; j++)
        {
            if(la->data[i] == lb->data[j])
            {
                break;
            }
            if(j == lb->length-1)//没找到，说明不是交集
            {   int k=i;
                for(k; k<la->length; k++)
                {
                    la->data[k] = la->data[k+1]; //前移一个进行覆盖
                }
                la->length--;
            }
        }
        
    }
}

void intersection2(pseqlist la, pseqlist lb) //删除相同的
{   
    int tempa;
    for(int i=0; i<la->length; i++)
    {
        for(int j=0; j<lb->length; j++)
        {
            if(la->data[i] == lb->data[j])
            {
                int k=i;
                for(k; k<la->length; k++)
                {
                    la->data[k] = la->data[k+1]; //前移一个进行覆盖
                }
                la->length--;
            }
           
        }
        
    }
}

void output(pseqlist la)
{
    for(int i=0; i<la->length; i++)
    {
        cout<<la->data[i]<<" ";
    }
}

int main()
{   int n1,n2,n3;
    cin>>n1>>n2>>n3;
    pseqlist la = input(n1), lb = input(n2), lc = input(n3);
    intersection(lb,lc);
    intersection2(la,lb);
    output(la);
    return 0;
}