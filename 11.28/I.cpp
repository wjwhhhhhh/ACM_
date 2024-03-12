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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> cnt;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cnt.push_back({a, b});
    }
    sort(cnt.begin(), cnt.end());
    int ing = 0, time = 0;
    for (auto [x, y] : cnt)
    {
        if (x - time - 1 < y && ing + x - time != y)
        {
            cout << "No\n";
            return;
        }
        ing = y, time = x;
    }
    cout << "Yes\n";
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