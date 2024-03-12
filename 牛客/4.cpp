#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
auto dijkstra(int s, auto &g)
{
    std::vector<int> dis(n, -1);
    using PII = std::pair<int, int>;
    std::priority_queue<PII, std::vector<PII>, std::greater<>> h;
    h.emplace(0, s);
    while (!h.empty())
    {
        auto [d, u] = h.top();
        h.pop();

        if (dis[u] != -1)
            continue;
        dis[u] = d;

        for (auto [v, w] : g[u])
        {
            h.emplace(d + w, v);
        }
    }
    return dis;
}
int n, m, k, a, b;
vector<vector<pair<int, int>>> edge, ed;
int Astar(int begin, int end, int k, vector<int> &from)
{
    auto hh=dijkstra(end,edge);
    std::priority_queue<array<int,3>, std::vector<array<int,3> >, std::greater<array<int,4> >> h;
    vector<int> dist(n,0x3f3f3f3f);
    dist[begin]=0;
    h.push({0,1,begin});
    int cnt=0;
    while(h.size())
    {
        auto u=h.top();
        int now=u[2];
        if(now==end)cnt++;
        if(cnt==k)return 0;
        for(auto [next,_y]:ed[now])
        {
            from[next]=now;
            h.push({u[0]+_y,hh[next],next});
        }
    }
    return -1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> k >> a >> b;
    a--,b--;
    vector<int> from(n);
    edge.resize(n), ed.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge[b].push_back({a, c});
        ed[a].push_back({b, c});
    }
    if(Astar(a, b, k, from)==-1)cout<<"No"<<'\n';
    else 
    return 0;
}