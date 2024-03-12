#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define endl '\n'
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx = 1;
void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
vector<int> f(N + 1), sum(N + 1);
vector<int> tt(N + 1), w(N + 1);
void dfs(int u, int fa)
{
    vector<int> ans;
    f[u] = sum[u] = 0;
    int ma = 0, who1 = 0, who2 = 0;
    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            if (tt[j] == 3)
                ans.push_back(j);
            dfs(j, u);
            ma = max(ma, w[j]);
            sum[u] += f[j];
            if (who1 < sum[j] + w[j] - f[j])
                who2 = who1, who1 = sum[j] + w[j] - f[j];
            else if (who2 < sum[j] + w[j] - f[j])
                who2 = sum[j] + w[j] - f[j];
        }
    }
    f[u] = sum[u] + ma;
    if (ans.size())
    {
        for (auto i : ans)
        {
            if (sum[i] + w[i] - f[i] == who1)
                f[u] = max(f[u], sum[u] + w[i] + who2);
            else
                f[u] = max(f[u], sum[u] + w[i] + who1);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    memset(h, 0, 8 * (n + 5));
    idx = 1;
    fir(i, 1, n) cin >> w[i];
    fir(i, 1, n) cin >> tt[i];
    fir(i, 1, n - 1)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dfs(1, -1);
    cout << f[1] + w[1] << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}