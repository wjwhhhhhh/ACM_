#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1e8 + 7;
const int N = 1e5 + 10;
bool fl = false;
i64 qmi(i64 p, i64 k, i64 M = M)
{
    i64 res = 1;
    while (k)
    {
        if (k & 1)
            res = res * p % M;
        p = p * p % M;
        k >>= 1;
    }
    return res;
}
i64 val[10 * N];
i64 tag[10 * N];
void pushup(int p, int l, int r)
{
    if (l == r)
        return;
    val[p << 1] *= tag[p];
    tag[p << 1] *= tag[p];
    tag[p << 1] %= M;
    val[p << 1] %= M;
    val[p << 1 | 1] *= tag[p];
    tag[p << 1 | 1] *= tag[p];
    tag[p << 1 | 1] %= M;
    val[p << 1 | 1] %= M;
    tag[p] = 1;
}
void modify(int p, int l, int r, int c, int s)
{
    if (l == r)
    {
        val[p] += s;
        val[p] %= M;
        val[p] = (val[p] + M) % M;
        return;
    }
    pushup(p, l, r);
    int mid = l + r >> 1;
    if (c <= mid)
        modify(p << 1, l, mid, c, s);
    else
        modify(p << 1 | 1, mid + 1, r, c, s);
    val[p] = val[p << 1] + val[p << 1 | 1];
    val[p] %= M;
    val[p] = (val[p] + M) % M;
    return;
}
void gree(int p, int a)
{
    val[p] *= a;
    val[p] %= M;
    tag[p] *= a;
    tag[p] %= M;
    return;
}
i64 get(int p, int l, int r, int ll, int rr)
{
    if (l == ll && r == rr)
    {
        return val[p] % M;
    }
    int mid = l + r >> 1;
    pushup(p, l, r);
    if (rr <= mid)
        return get(p << 1, l, mid, ll, rr);
    else if (ll > mid)
        return get(p << 1 | 1, mid + 1, r, ll, rr);
    else
        return get(p << 1, l, mid, ll, mid) + get(p << 1 | 1, mid + 1, r, mid + 1, rr);
}
i64 fac[2 * N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a;
    cin >> n >> m >> a;
    for (int i = 0; i <= 4 * N; i++)
        tag[i] = 1;
    fac[N] = 1;
    for (int i = N + 1; i < 2 * N; i++)
        fac[i] = fac[i - 1] * a % M;
    i64 ni = qmi(a, M - 2) % M;
    for (int i = N - 1; i >= 0; i--)
        fac[i] = fac[i + 1] * ni % M;
    vector<vector<int>> edge(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int tem;
        cin >> tem;
        edge[tem].push_back(i);
        edge[i].push_back(tem);
    }
    using two = array<int, 2>;
    vector<vector<two>> que(n + 1);
    vector<vector<int>> at(n + 1);
    vector<int> has;
    for (int i = 1; i <= m; i++)
    {
        int fl;
        cin >> fl;
        if (fl == 1)
        {
            int v, x;
            cin >> v >> x;
            que[v].push_back({i, x});
        }
        else
        {
            has.push_back(i);
            int v;
            cin >> v;
            at[v].push_back(i);
        }
    }
    vector<i64> ans(m + 1);
    function<void(int, int)> dfs = [&](int u, int fa) {
        gree(1, a);
        for (auto [x, y] : que[u])
        {
            modify(1, 1, m, x, fac[y + N]);
        }
        for (auto c : at[u])
        {
            ans[c] = get(1, 1, m, 1, c);
        }
        for (auto c : edge[u])
        {
            if (c == fa)
                continue;
            dfs(c, u);
        }
        for (auto [x, y] : que[u])
        {
            modify(1, 1, m, x, -fac[y + N]);
        }
        gree(1, ni);
    };
    dfs(1, -1);
    for (auto c : has)
    {
        cout << (ans[c] % M + M) % M << "\n";
    }
    return 0;
}