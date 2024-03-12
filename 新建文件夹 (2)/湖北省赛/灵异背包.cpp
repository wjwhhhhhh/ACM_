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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    i64 ans = 0;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        if (tem & 1)
            a.push_back(tem);
        else
            ans += tem;
    }
    sort(a.begin(), a.end());
    for (int i = (int)a.size() - 1; i >= 1; i -= 2)
    {
        ans += (a[i] + a[i - 1]);
    }
    cout << ans << endl;
    return 0;
}