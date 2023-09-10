#include <iostream>
#include <cstring>
#include<stdio.h>
using namespace std;
char a[100],b[100];
int c[100][100];
int lcs(char a[],char b[],int c[100][100]);
int main()
{   cin>>a>>b;
    int ans;
    ans=lcs(a,b,c);
    cout <<ans<< endl;
    return 0;
}

int lcs(char a[],char b[],int c[100][100])
{   int m=strlen(a);
    int n=strlen(b);
    int i,j;
    for(i=0;i<=m;i++)
        c[0][i]=0;
    for(j=0;j<=n;j++)
        c[j][0]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i-1]==b[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);

        }
    return c[m][n];
}
