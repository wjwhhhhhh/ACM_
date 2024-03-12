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
    vector<int> a(n);
    fir(i, 0, n) cin >> a[i];
    map<int, vector<int>> mp;
    vector<int> ans(n, 3);
    fir(i, 0, n) mp[a[i]].push_back(i);
    vector<int> all;
    for (auto [x, cnt] : mp)
    {
        if (cnt.size() > 1)
            all.push_back(x);
    }
    // cerr << "ok" << endl;
    if (all.size() < 2)
    {
        cout << "-1" << endl;
        return;
    }
    ans[mp[all[0]][0]] = 1;
    for (auto c : mp[all[1]])
        ans[c] = 2;
    ans[mp[all[1]][0]] = 1;
    for (auto c : ans)
        cout << c << ' ';
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