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
    int idx = 0;
    set<int> has;
    int fl = -1;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        has.insert(a[i]);
    while (1)
    {
        if (has.find(idx) == has.end())
        {
            if (fl == -1)
            {
                fl = idx;
                has.insert(fl);
            }
            else
                break;
        }
        idx++;
    }
    cout << fl << endl;
    while (1)
    {
        int b;
        cin >> b;
        if (b == -1)
            return;
        cout << b << endl;
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