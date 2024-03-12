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
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    vector<array<int, 30>> st(n);
    for (auto c : st)
        fill(c.begin(), c.end(), -1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = (1 << 30) - 1;
        for (int j = 0; j < n; j++)
            if (j != i)
                ans[i] &= a[i][j];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && (ans[i] | ans[j]) != a[i][j])
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (auto c : ans)
        cout << c << " ";
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