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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(3) << fixed;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < n; j++)
        cin >> b[j];
    for (int i = 0; i < n; i++)
        a[i]--, b[i]--;
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
        idx[b[i]] = i;
    for (int i = 0; i < n; i++)
    {
        a[i] = idx[a[i]];
        b[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        idx[a[i]] = i;
    }
    vector<double> ans(n);
    ans[0] = 1, ans[1] = 2;
    set<int> s;
    vector<double> dp(n);
    dp[0] = 0;
    dp[1] = 1;
    vector<int> c(n, 0);
    for (int i = 2; i < n; i++)
    {
        if (idx[i - 1] > idx[i])
        {
            ans[i] = ans[i - 1] + 1;
        }
        else if (idx[i - 1] + 1 < idx[i])
        {
            ans[i] = ans[i - 1] + 1;
        }
        else
        {
        }
        // double ma = 0;
        // for (int j = 1; j < i; j++)
        // {
        //     if (idx[j] < idx[i])
        //         ma = max(ma, ans[idx[j]] + 1);
        // }
        // ans[i] = min(ans[i], ma);
    }
    cout << ans[n - 1] << endl;
    return 0;
}