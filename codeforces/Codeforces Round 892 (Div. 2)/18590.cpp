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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    bool fl = true;
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            fl = false;
    if (fl)
    {
        cout << "-1" << endl;
        return;
    }
    vector<int> b, c;
    int ma = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] == ma)
            c.push_back(ma);
        else
            b.push_back(a[i]);
    }
    cout << b.size() << " " << c.size() << endl;
    for (auto ch : b)
        cout << ch << " ";
    cout << endl;
    for (auto ch : c)
        cout << ch << " ";
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