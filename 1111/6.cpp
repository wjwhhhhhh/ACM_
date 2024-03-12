#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    using two=array<int,2> ;
    vector<vector<two>> edge(n);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge[u].push_back({v,w});
    }
    while(q--)
    {
        int u,v,k;
        cin>>u>>v>>k;

    }
}

2023年百度之星程序设计大赛初赛