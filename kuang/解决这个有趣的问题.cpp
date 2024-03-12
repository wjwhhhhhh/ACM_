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
const int N = 1e9;
int ans = 0;
void dfs(int l, int r)
{
    if (l < 0 || ans <= r)
        return;
    if (l == 0)
    {
        ans = r;
        return;
    }
    if (r - l + 1 > l)
        return;
    dfs((l - 1) * 2 - r + 1, r);
    dfs((l - 1) * 2 - r, r);
    dfs(l, 2 * r - l + 1);
    dfs(l, 2 * r - l);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int l, r;
    while (cin >> l >> r)
    {
        ans = N;
        dfs(l, r);
        if (ans == N)
            cout << "-1" << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}