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
    int n, k;
    cin >> n >> k;
    vector<array<int, 20>> f(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        f[i][0] = a[i];
    for (int j = 1; j < 20; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }
    auto ask = [&](int l, int r) {
        if (r == -1 || l == n)
            return -1;
        int len = r - l + 1;
        len = __lg(len);
        return max(f[l][len], f[r - (1 << len) + 1][len]);
    };
    vector<int> ans(k, -1);
    for (int i = 0; i < n; i++)
    {
        if (ans[a[i] - 1] != -1)
            continue;
        int l = 0, r = i;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (ask(0, mid) >= a[i])
                r = mid;
            else
                l = mid + 1;
        }
        int tr = l;
        // cerr << "ok" << endl;
        l = i, r = n;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (ask(mid, n - 1) >= a[i])
                l = mid;
            else
                r = mid - 1;
        }
        // cout << l << endl;
        ans[a[i] - 1] = l - tr + 1 << 1;
    }
    for (int i = 0; i < k; i++)
        cout << (ans[i] == -1 ? 0 : ans[i]) << " ";
    cout << endl;
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