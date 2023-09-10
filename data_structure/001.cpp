#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

# define maxnum 100

typedef struct seqlist
{
    int data[maxnum];
    int length;
}seqlist, *pseqlist;

void insert(pseqlist l, int val)
{
    if(l->length == 0)
    {
        l->data[0] = val;
        l->length++;
    }

    int i;
    for(i=0; i<l->length; i++)
    {
        if(val<l->data[i])
        {
            int temp = l->data[i];
            for(int j=l->length; j>=i; j--)
            {
                l->data[j+1] = l->data[j];
            }
            l->data[i] = val;
            l->length++;
            break;
        }
    }

}
void output(seqlist l)
{
    for(int i=0; i<l.length; i++)
    {
        cout<<l.data[i]<<" ";
    }
}
int main()
{   seqlist l;
    int n,val;
    cin>>n;l.length=n;
    for(int i=0; i<n; i++)
    {
        cin>>l.data[i];
    }
    cin>>val;
    insert(&l,val);
    output(l);

    return 0;
}