#include <bits/stdc++.h>
using namespace std;
using i64=long long;
const int N=1010,M=200010;
int dist[N];
int h[N],e[M],ne[M],idx=1,w[M];
void add(int a,int b,int c)
{
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
int q[N];
int hh=0,tt=0;
bool v[N];
int t[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>t[i];
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    q[tt++]=1;
    v[1]=true;
    while(hh!=tt)
    {
        int x=q[hh++];
        if(hh==N)hh=0;
        for(int i=h[x];i;i=ne[i])
        {
            int j=w[i];
            if(dist[j]>dist[x]+w[i])
            {
                dist[j]=dist[x]+w[i];
                if(v[j])
                {
                    q[tt++]=j;
                    if(tt==N)
                    {
                        tt=0;
                    }
                }
            }
        }
    }
    cout<<max(0,dist[n]-t[1]);
    return 0;
}