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
const int M = 2e5;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    set<int> t1, t2;
    for (int i = 0; i < n; i++)
        t1.insert(a[i]);
    for (int i = 0; i < m; i++)
        t2.insert(b[i]);
    for (int i = M; i > 0; i--)
    {
        bool f1 = false, f2 = false;
        for (int j = i; j <= M; j += i)
        {
            if (t1.find(j) != t1.end())
                f1 = true;
            if (t2.find(j) != t2.end())
                f2 = true;
        }
        if (f1 && f2)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}