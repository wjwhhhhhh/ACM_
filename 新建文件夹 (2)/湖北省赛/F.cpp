#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
const int N = 410;
int g[N][N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    memset(g, 0x3f, sizeof g);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        chmin(g[x][y], c);
    }
    for (int i = 0; i < N; i++)
        g[i][i] = 0;
    for (int k = 1; k < N; k++)
        for (int i = 1; i < N; i++)
            for (int j = 1; j < N; j++)
            {
                chmin(g[i][j], g[i][k] + g[k][j]);
            }
    i64 ans = 0, res = 1e18;
    for (int i = 0; i < n; i++)
    {
        ans = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] != b[(i + j) % n])
            {
                ans += min(g[b[(i + j) % n]][a[j]], g[a[j]][b[(i + j) % n]]);
            }
        }
        chmin(res, ans);
    }
    if (res >= 0x3f3f3f3f)
        cout << "-1";
    else
        cout << res << endl;
    return 0;
}