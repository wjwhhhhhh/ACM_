#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
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
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;
    if (mp.size() == 1)
    {
        cout << "Yes" << endl;
        return;
    }
    else if (mp.size() == 2)
    {
        int x = mp.begin()->second, y = mp.rbegin()->second;
        if (abs(x - y) < 2)
        {
            cout << "Yes" << endl;
            return;
        }
        else
        {
            cout << "No" << endl;
            return;
        }
    }
    else
    {
        cout << "No" << endl;
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