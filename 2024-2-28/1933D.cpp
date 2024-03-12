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
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int tem = *min_element(a.begin(), a.end());
    int sum = count(a.begin(), a.end(), tem);
    if (sum == 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        bool fl = false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] % tem != 0)
                fl = true;
        }
        if (fl)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
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