#include <iostream>
#include <cstring>
using namespace std;
int l[100][100];
int lcs_length(char x[], char y[]);
int main()
{   char x[100],y[100];
    int len;
    while(1)
    {
        cin>>x>>y;
        if(x[0]=='0')
            break;
        len=lcs_length(x,y);
        cout<<len;
    }
    cout << "Hello world!" << endl;
    return 0;
}

int lcs_length(char x[], char y[])
{
    int m,n,i,j;
     m=strlen(x);
     n=strlen(y);
    for(i=0;i<=m;i++)
        l[0][i]=0;
    for(j=0;j<=n;j++)
        l[j][0]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
    {
        if(x[i-1]=y[j-1])
            l[i][j]=l[i-1][j-1]+1;
        else
        {
             if(l[i-1][j]>=l[i][j-1])
                l[i][j]=l[i-1][j];
            else l[i][j]=l[i][j-1];

        }
        

    }
	return l[m][n];
}

