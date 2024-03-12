#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define int long long
using namespace std;
using i64 = long long;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n);
    vector<vector<i64>> ww(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        assert(c > 0);
        edge[a].push_back(b);
        edge[b].push_back(a);
        ww[a].push_back(c);
        ww[b].push_back(c);
    }
    priority_queue<pair<i64, int>> st;
    vector<i64> dist(n, 1e18);
    vector<int> v(n);
    dist[n - 1] = 0;
    st.push({-dist[n - 1], n - 1});
    while (st.size())
    {
        auto fr = st.top().second;
        st.pop();
        if (v[fr])
            continue;
        v[fr] = true;
        for (int i = 0; i < edge[fr].size(); i++)
        {
            if (dist[edge[fr][i]] > dist[fr] + ww[fr][i])
            {
                dist[edge[fr][i]] = dist[fr] + ww[fr][i];
                st.push({-dist[edge[fr][i]], edge[fr][i]});
            }
        }
    }
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return dist[x] < dist[y]; });
    vector<int> ans(n);
    for (int i = 1; i < n; i++)
    {
        set<int> all;
        i64 res = 1e18;
        for (int j = 0; j < edge[o[i]].size(); j++)
        {
            if (res == ww[o[i]][j] + dist[edge[o[i]][j]])
            {
                all.insert(ans[edge[o[i]][j]]);
            }
            else if (res > ww[o[i]][j] + dist[edge[o[i]][j]])
            {
                all.clear();
                res = ww[o[i]][j] + dist[edge[o[i]][j]];
                all.insert(ans[edge[o[i]][j]]);
            }
        }
        int idx = 0;
        while (all.find(idx) != all.end())
            idx++;
        ans[o[i]] = idx;
    }
    if (ans[0])
    {
        cout << "Little M is the winner." << endl;
    }
    else
    {
        cout << "Little I is the winner." << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}