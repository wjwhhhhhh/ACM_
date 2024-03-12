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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = n - 1; i > 0; i--)
        a[i] = a[i] - a[i - 1];
    for (int i = 1; i < n; i++)
    {
        mp[abs(a[i])]++;
    }
    cout << (mp.rbegin()->first) << endl;

    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        if (l != 0)
        {
            mp[abs(a[l])]--;
            if (mp[abs(a[l])] == 0)
                mp.erase(abs(a[l]));
            a[l] += x;
            mp[abs(a[l])]++;
        }
        if (r + 1 != n)
        {
            mp[abs(a[r + 1])]--;
            if (mp[abs(a[r + 1])] == 0)
                mp.erase(abs(a[r + 1]));
            a[r + 1] -= x;
            mp[abs(a[r + 1])]++;
        }
        cout << (mp.rbegin()->first) << endl;
    }
    return 0;
}