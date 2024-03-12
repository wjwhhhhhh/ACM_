#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
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
const int N = 1e3 + 10;
i64 w[N][N];
i64 d[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> d[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            w[i][j] = d[i][j] * a;
        }
    }
    vector<i64> dist(n, 1e18);
    vector<int> v(n);
    dist[0] = 0;
    priority_queue<pair<i64, int>> st;
    st.push({0, 0});
    while (st.size())
    {
        auto x = st.top().second;
        st.pop();
        if (v[x])
            continue;
        v[x] = true;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] > dist[x] + w[x][i])
            {
                dist[i] = dist[x] + w[x][i];
                st.push({-dist[i], i});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            w[i][j] = d[i][j] * b + c;
        }
    }
    vector<i64> dis(n, 1e18);
    vector<int> vis(n);
    dis[n - 1] = 0;
    st.push({0, n - 1});
    while (st.size())
    {
        auto x = st.top().second;
        st.pop();
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = 0; i < n; i++)
        {
            if (dis[i] > dis[x] + w[x][i])
            {
                dis[i] = dis[x] + w[x][i];
                st.push({-dis[i], i});
            }
        }
    }
    i64 ans = dist[0] + dis[0];
    for (int i = 0; i < n; i++)
    {
        chmin(ans, dist[i] + dis[i]);
    }
    cout << ans << endl;
    return 0;
}