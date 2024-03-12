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
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return a[x] < a[y]; });
    i64 sum = a[o[0]] + a[o[n - 1]];
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        if (sum != a[o[i]] + a[o[n - i - 1]])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    vector<two> ans;
    if (n & 1)
    {
        swap(a[n / 2], a[o[n / 2]]);
        ans.push_back({n / 2, o[n / 2]});
    }
    vector<int> idx(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return a[x] < a[y]; });
    vector<int> dui(n);
    for (int i = 0; i < n; i++)
    {
        dui[o[i]] = o[n - 1 - i];
    }
    iota(o.begin(), o.end(), 0);
    iota(idx.begin(), idx.end(), 0);
    for (int i = 0; i < n / 2; i++)
    {
        if (dui[o[i]] == o[n - 1 - i])
            continue;
        else
        {
            ans.push_back(two{idx[dui[o[i]]], n - 1 - i});
            int x = o[n - i - 1];
            int y = dui[o[i]];
            swap(o[idx[y]], o[n - 1 - i]);
            swap(idx[x], idx[y]);
        }
    }
    cout << ans.size() << endl;
    for (auto [x, y] : ans)
    {
        cout << x + 1 << " " << y + 1 << '\n';
    }
    return;
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