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
    string a;
    cin >> a;
    vector<int> l(n);
    l[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= a[l[i + 1]])
            l[i] = i;
        else
            l[i] = l[i + 1];
    }
    vector<int> all;
    int ing = 0;
    while (ing != n)
    {
        all.push_back(l[ing]);
        ing = l[ing] + 1;
    }
    string b = a;
    for (int i = 0; i < all.size(); i++)
    {
        b[all[i]] = a[all[all.size() - i - 1]];
    }
    if (!is_sorted(b.begin(), b.end()))
    {
        cout << "-1" << '\n';
        return;
    }
    int ans = all.size();
    for (int i = 0; i < all.size(); i++)
    {
        if (a[all[i]] == a[all[0]])
            ans--;
    }
    cout << ans << endl;
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