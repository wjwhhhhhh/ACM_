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
string th = "RB";
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    if (n - 1 + m - 1 > k || (k - n - m + 2) & 1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int ing = 0;
    vector<int> ans;
    for (int i = 1; i < m; i++)
    {
        ans.push_back(ing);
        ing ^= 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (auto c : ans)
            cout << th[c] << " ";
        cout << endl;
    }
    ans.clear();
    for (int i = 1; i < n; i++)
    {
        ans.push_back(ing);
        ing ^= 1;
    }
    for (int i = 0; i < m; i++)
    {
        for (auto c : ans)
            cout << th[c] << " ";
        cout << endl;
    }
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