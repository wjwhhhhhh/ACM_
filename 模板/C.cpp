#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 3e3+10,M=N*N;
int h[N],e[N],ne[N],idx=1;
int n1,n2,m,res=0;
int match[M];
bool st[M];
void add(int x,int y)
{
    e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}
bool find(int x)
{
    for(int i=h[x];i!=0;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            st[j]=1;
            if(match[j]==0||find(match[j]))
            {
                match[j]=x;
               return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int n,m;
    cin>>n;
    m=n*(n-1)/2;
    int n1=n,n2=n;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        int a;
        cin>>a;
        if(a)add(i,j);
    }
    for(int i=1;i<=n1;i++)
    {
        memset(st, 0, sizeof st);
       if(find(i))res++;
    }
    cout<<res;
}