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
    int a, b;
    cin >> a >> b;
    vector<int> f(100);
    for (int i = a; i < 100; i++)
    {
        set<int> has;
        for (int j = a; j <= b; j++)
            has.insert(f[i - j]);
        int idx = 0;
        while (has.find(idx) != has.end())
            idx++;
        f[i] = idx;
    }
    for (int i = 1; i < 100; i++)
        cout << f[i] << endl;
    return 0;
}