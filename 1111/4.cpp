#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> fa(n+1);
    for(int i=1;i<=n;i++)cin>>fa[i];
    vector<int> st(n+1);
    for(int i=1;i<=n;i++)if(fa[i]==0)st[i]=true;
    for(int i=1;i<=n;i++)
    {
        if(st[i])continue;
        vector<int> has(n+1);
        has[i]=true;
        int ing=fa[i];

        while(!st[ing]&&!has[ing])
        {
            has[ing]=true;
            ing=fa[ing];
        }

        if(st[ing])st[i]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(st[i])
        {ans^=i;
         //cout<<i<<endl;
        }
    }
    cout<<ans<<"\n";
}