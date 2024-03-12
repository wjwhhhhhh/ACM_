#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a(4), b(4);
    for (int i = 0; i < 4; i++)
    {
        a[i] = s1[i] - '0';
        b[i] = s2[i] - '0';
    }
    for (int i = 0; i < 4; i++)
    {
        a[i] = (a[i] - b[i] + 10) % 10;
    }
    int ans = 1e9;
    function<void(int, int, int)> dfs = [&](int idx, int res, int last) {
        if (idx == 4)
        {
            chkmin(ans, res);
            return;
        }
        if (last >= 0)
        {
            if (a[idx] + last >= 9)
            {
                dfs(idx + 1, res, min())
            }
        }
    };
    dfs(0, 0, 0);
    cout << ans << endl;
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