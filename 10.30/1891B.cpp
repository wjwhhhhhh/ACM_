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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    fir(i, 0, n) cin >> a[i];
    vector<int> all;
    fir(i, 0, m)
    {
        int tem;
        cin >> tem;
        if (all.size() == 0 || all.back() > tem)
            all.push_back(tem);
    }
    fir(i, 0, n)
    {
        for (auto c : all)
        {
            if (a[i] % (1 << c) == 0)
                a[i] += (1 << c - 1);
        }
        cout << a[i] << ' ';
    }
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