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
const int M = 1e6 + 10;
vector<int> a(M);
void solve()
{
    int l, r, x;
    cin >> l >> r >> x;
    if (a[r - l + 1] < x)
    {
        cout << "-1" << '\n';
        return;
    }
    function<void(int, int, int, int &)> dfs = [&](int l, int r, int ci, int &ans) {
        if (ci == 1)
        {
            ans = (l + r) >> 1;
            return;
        }
        int mid = l + r >> 1;
        if (a[mid - l + 1] > a[r - mid])
        {
            dfs(l, mid - 1, ci - 1, ans);
        }
        else
            dfs(mid + 1, r, ci - 1, ans);
    };
    int ans = 0;
    dfs(l, r, x, ans);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    a[1] = 1;
    for (int i = 2; i < M; i++)
    {
        int mid = i + 1 >> 1;
        a[i] = max(a[mid - 1], a[i - mid]) + 1;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}