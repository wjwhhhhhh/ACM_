#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
// #define int long long
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1), w(n + 1);
    vector<vector<int>> pp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        for (int j = 1; j < p[i]; j++)
        {
            int tem;
            cin >> tem;
            pp[i].push_back(tem);
        }
        cin >> w[i];
        pp[i].push_back(w[i]);
    }
    vector<vector<int>> zh(n + 1, vector<int>(k + 1, -1e9)), fa(n + 2, vector<int>(k + 1, -1e9));
    zh[0][0] = 0, fa[n + 1][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            chmax(zh[i][j], zh[i - 1][j]);
            if (j - p[i] >= 0)
                chmax(zh[i][j], zh[i - 1][j - p[i]] + w[i]);
        }
    }
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j <= k; j++)
        {
            chmax(fa[i][j], fa[i + 1][j]);
            if (j - p[i] >= 0)
                chmax(fa[i][j], fa[i + 1][j - p[i]] + w[i]);
        }
    }
    int ans = 0, sum = 0;
    for (int i = 1; i <= n; i++)
        sum += p[i];
    if (sum <= k)
    {
        for (int i = 0; i <= k; i++)
            chmax(ans, zh[n][i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p[i]; j++)
        {
            for (int z = 0; z <= k - j; z++)
            {
                if (zh[i - 1][z] >= 0 && fa[i + 1][k - j - z] >= 0)
                    chmax(ans, zh[i - 1][z] + fa[i + 1][k - j - z] + pp[i][j - 1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}