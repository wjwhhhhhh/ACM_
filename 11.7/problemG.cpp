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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = -1, a[n + 1] = -1;
    vector<int> l(n + 2), r(n + 2);
    l[0] = 0, r[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        l[i] = i - 1, r[i] = i + 1;
    }
    l[n + 1] = n, r[n + 1] = 0;
    int has = n;
    int all = 0;
    while (has != 1)
    {
        int ing = r[0];
        int si = 0;
        set<int> al;
        while (ing != 0 && ing != n + 1)
        {
            bool fl = (a[l[ing]] > a[ing]) | (a[r[ing]] > a[ing]);
            if (fl)
            {
                si++;
                al.insert(a[ing]);
            }
            ing = r[ing];
        }
        ing = r[0];
        while (ing != 0 && ing != n + 1)
        {
            if (al.find(a[ing]) != al.end())
            {
                r[l[ing]] = r[ing];
                l[r[ing]] = l[ing];
            }
            ing = r[ing];
        }
        has -= si;
        all++;
    }
    cout << all << endl;
    return 0;
}