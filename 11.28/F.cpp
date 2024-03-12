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
    int p;
    cin >> p;
    set<int> has;
    for (int i = 0; i < p; i++)
    {
        int a;
        cin >> a;
        has.insert(a);
    }
    if (n == 1)
    {
        cout << "No" << endl;
        return;
    }
    bool fl = false;
    int id = -1;
    for (int i = 1; i < n; i++)
    {
        int p;
        cin >> p;
        vector<int> a(p);
        bool tr = true;
        for (int i = 0; i < p; i++)
        {
            cin >> a[i];
            // cout << a[i] << endl;
            if (has.find(a[i]) != has.end())
                tr = false;
        }
        if (tr)
        {
            fl = true;
            // cout << i << "ok" << endl;
            id = i;
            // cout << id << "ok" << endl;
        }
        has.clear();
        for (auto c : a)
            has.insert(c);
    }
    if (!fl)
    {
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    swap(o[id], o[id - 1]);
    for (int i = 0; i < n; i++)
    {
        cout << o[i] + 1;
        if (i != n - 1)
            cout << " ";
    }
    cout << '\n';
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