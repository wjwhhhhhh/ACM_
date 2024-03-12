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
    set<int> has;
    int idx = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        a[i] = tem;
        has.insert(tem);
    }
    while (has.find(idx) != has.end())
        idx++;
    if (idx == 1)
    {
        bool fl = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i])
                fl = true;
        }
        if (!fl)
        {
            assert(1);
            i64 ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == 0)
                {
                    i64 res = 0;
                    for (int j = i; j >= 0; j--)
                    {
                        if (a[j] == 0)
                            break;
                        chmax(ans, __gcd(res, (i64)a[j]));
                    }
                    for (int j = i; j < n; j++)
                    {
                        if (a[j] == 0)
                            break;
                        chmax(ans, __gcd(res, (i64)a[j]));
                    }
                }
            }
            cout << ans << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    else
    {
    }
    return 0;
}