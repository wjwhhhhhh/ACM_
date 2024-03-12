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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Tree_array<int> tr(n + 1);
    for (int i = 0; i < n; i++)
        tr.insert(i + 1, a[i]);
    a.push_back(0x3f3f3f3f);
    vector<int> l(n + 1), r(n + 1);
    l[n] = n;
    r[0] = a[0];
    for (int i = 1; i <= n; i++)
    {
        r[i] = max(a[i], r[i - 1]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] < a[l[i + 1]])
        {
            l[i] = i;
        }
        else
        {
            l[i] = l[i + 1];
        }
    }
    int ans = 0, ing = 0;
    while (ing != n)
    {
        int zh = a[ing];
        if (a[l[ing + 1]] == zh && a[ing + 1] == zh)
        {
            ans++;
            ing++;
        }
        else if (a[l[ing + 1]] > zh)
        {
            ans++;
            ing++;
        }
        else
        {
            while (a[l[ing + 1]] < r[ing])
            {
                ing = l[ing + 1];
            }
            ing++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}