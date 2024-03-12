#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<int, 2>;
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
    int n;
    cin >> n;
    vector<int> a(n);
    fir(i, 0, n) cin >> a[i];
    for (int i = n - 2; i >= 0; i--)
    {
        a[i] = max(a[i], a[i + 1] - 1);
    }
    int idx = 1;
    vector<int> ans(1, 0);
    ans.push_back(1);
    idx++;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0)
        {
            ans.push_back(idx++);
        }
        else
            ans.push_back(ans[a[i]]);
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}