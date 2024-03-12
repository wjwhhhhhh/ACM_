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
    if (is_sorted(a.begin(), a.end()))
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    int l, r;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
        {
            l = i;
            break;
        }
    }
    r = min_element(a.begin() + l + 1, a.end()) - a.begin();
    reverse(a.begin() + l, a.begin() + r + 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
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