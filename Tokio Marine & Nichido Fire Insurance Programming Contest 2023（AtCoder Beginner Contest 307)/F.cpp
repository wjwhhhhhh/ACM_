#include <bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
struct Graph // 有向图
{
    std::vector<int> e, ne, h, w;
    int idx = 0;
    int node_size;
    Graph()
    {
    }
    Graph(int n)
    {
        init(n);
    }
    Graph(int n, int m)
    {
        init(n, m);
    }
    void init(int n)
    {
        node_size = n;
        idx = 0;
        e.resize(2 * n), ne.resize(2 * n), w.resize(2 * n);
        h.resize(n, -1);
    }
    void init(int n, int m)
    {
        node_size = n;
        idx = 0, e.resize(m), ne.resize(m), w.resize(m);
        h.resize(n, -1);
    }
    void add(int a, int b)
    {
        e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void add(int a, int b, int c)
    {
        w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }
    void clear(int si = 0) // 清空图
    {
        if (si == 0)
            si = node_size;
        idx = 0;
        fill(h.begin(), h.begin() + si, -1);
    }
    void dfs(int u, int fath = -1)
    {
        for (int i = h[u]; ~i; i = ne[i])
        {
            int j = e[i];
            if (j != fath)
            {
                dfs(j, u);
            }
        }
    }
};
struct UNdigraph : Graph // 无向图
{
    UNdigraph()
    {
    }
    UNdigraph(int a) : Graph(a)
    {
    }
    UNdigraph(int n, int m) : Graph(n, m)
    {
    }
    void insert(int a, int b)
    {
        add(a, b), add(b, a);
    }
    void insert(int a, int b, int c)
    {
        add(a, b, c), add(b, a, c);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    UNdigraph gra(n + 100, 2 * (m + n + 100));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        gra.insert(a, b, c);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        gra.insert(0, t, 0);
    }
    vector<i64> dist(n + 1, 1e18);
    vector<int> v(n + 1);
    dist[0] = 0;
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> st;
    st.push({0, 0});
    vector<int> ans(n + 1, -1);
    int d = 0;
    cin >> d;
    for (int i = 0; i <= d; i++)
    {
        int len = 0;
        if (i)
            cin >> len;
        vector<int> cnt;
        while (st.size() && st.top().first <= len)
        {
            auto y = st.top().second;
            st.pop();
            if (v[y])
                continue;
            v[y] = true;
            cnt.push_back(y);
            for (int i = gra.h[y]; ~i; i = gra.ne[i])
            {
                int j = gra.e[i], w = gra.w[i];
                if (dist[j] > dist[y] + w)
                {
                    dist[j] = dist[y] + w;
                    st.push({dist[j], j});
                }
            }
        }
        for (auto cn : cnt)
        {
            if (ans[cn] == -1)
                ans[cn] = i;
            for (int i = gra.h[cn]; ~i; i = gra.ne[i])
            {
                int j = gra.e[i], w = gra.w[i];
                if (dist[j] > w)
                {
                    dist[j] = w;
                    st.push({dist[j], j});
                }
            }
        }
        cnt.clear();
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}