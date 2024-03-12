#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vector<int> >edge(n);
    vector<int> T(m);
    for (int i = 0; i < m; i++)
    {
        int len;
        cin >> len>>T[i];
        for (int i = 0; i < len; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            edge[a].push_back(b), edge[b].push_back(a);
        }
    }
    vector<int> v(n),dist(n,-1);
    dist[s]=0;
    priority_queue<pair<int,int> > st;
    st.push({0,s});
    while(st.size())
    {
        auto si=st.top().second;
        st.pop();
        if(v[si])continue;
        v[si]=true;

    }
    return 0;
}