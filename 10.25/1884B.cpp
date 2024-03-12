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
    string a;
    cin >> a;
    i64 cnt = 0;
    vector<int> s0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '0')
            s0.push_back(i);
    }
    // int cnt = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (s0.size() == 0)
        {
            cout << "-1 ";
        }
        else
        {
            cnt += (i - s0.back());
            s0.pop_back();
            cout << cnt << " ";
        }
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