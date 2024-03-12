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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 2);
    string ch;
    cin >> ch;
    for (int i = 0; i < n; i++)
    {
        a[i + 1] = (ch[i] == '1');
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            while (a[i] == 1)
                i++;
            ans++;
        }
    }

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            cout << ans << '\n';
        }
        else if (a[l] == a[r] || (a[l - 1] == a[r + 1]))
        {
            cout << ans << '\n';
        }
        else if (a[l] != a[l - 1])
        {
            cout << ans - 1 << '\n';
        }
        else
            cout << ans + 1 << '\n';
    }
    return 0;
}