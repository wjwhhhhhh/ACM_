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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, k, p;
    cin >> n >> k >> p;
    p++;
    int si = pow(p, k);
    vector<vector<i64>> f(n + 1, vector<i64>(si, 1e12));
    vector<vector<int>> w(n + 1, vector<int>(k));
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        for (int j = 0; j < k; j++)
            cin >> w[i][j];
    }
    f[0][0] = 0;
    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i < si; i++)
        {
            f[j][i] = min(f[j][i], f[j - 1][i]);
            int tem = 0;
            for (int z = 0; z < k; z++)
            {
                int ch = min(p - 1, i / (int)pow(p, z) % p + w[j][z]);
                tem += ch * (int)pow(p, z);
            }
            f[j][tem] = min({f[j][tem], f[j - 1][tem], f[j - 1][i] + c[j]});
        }
    }
    cout << (f[n][si - 1] == 1e12 ? -1 : f[n][si - 1]) << endl;
    return 0;
}