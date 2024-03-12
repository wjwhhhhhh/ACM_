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
const int M = 998244353;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    map<int, int> s1, s2;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        s1[a[i]] = b[i];
    }
    int m;
    cin >> m;
    vector<int> a1(m), a2(m);
    for (int i = 0; i < m; i++)
        cin >> a1[i];
    for (int i = 0; i < m; i++)
        cin >> a2[i];
    i64 ans = 1;
    for (int i = 0; i < m; i++)
    {
        if (s1.find(a1[i]) == s1.end())
        {
            cout << 0 << endl;
            return 0;
        }
        s2[a1[i]] = a2[i];

        if (s1[a1[i]] != a2[i])
        {
            if (s1[a1[i]] < a2[i])
            {
                std::cout << "0\n";
                return 0;
            }
            ans = ans * 2 % M;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s2.find(a[i]) == s2.end())
            ans = ans * 2 % M;
    }
    cout << ans << endl;
    return 0;
}