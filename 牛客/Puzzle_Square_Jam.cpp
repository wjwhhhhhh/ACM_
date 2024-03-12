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
    int n, m;
    cin >> n >> m;
    if (n == 2 && m == 2)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<array<int, 3>> ans;
    function<void(int, int)> solve = [&](int l, int r) {
        if (l == 0 || r == 0)
            return;
        if (l == r)
        {
            ans.push_back({0, 0, l});
            return;
        }
        if (l > r)
        {
            ans.push_back({l - r, 0, r});
            solve(l - r, r);
        }
        else
        {
            ans.push_back({0, r - l, l});
            solve(l, r - l);
        }
    };
    solve(n, m);
    cout<<ans.size()<<'\n';
    for (auto [x, y, z] : ans)
        cout << x << " " << y << " " << z << '\n';
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