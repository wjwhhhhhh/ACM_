#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, vector<int>> mp;
    fir(i, 0, n)
    {
        mp[a[i]].push_back(i);
    }
    vector<int> fr, ba;
    for (auto [x, cnt] : mp)
    {
        fr.push_back(cnt[0]);
        ba.push_back(cnt.back());
    }
    sort(fr.begin(), fr.end());
    i64 ans = 0;
    for (auto i : ba)
    {
        // cout << i << endl;
        //  cout << "ok" << endl;
        ans += upper_bound(fr.begin(), fr.end(), i) - fr.begin();
    }
    cout << ans << endl;
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
1 5 5 5 5 2 3 3 5 7