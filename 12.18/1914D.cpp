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
i64 ans = 0;
void get(vector<int> a, vector<int> b, vector<int> c)
{
    i64 res = 0;
    int mi = max_element(a.begin(), a.end()) - a.begin();
    // cout << a[mi] << endl;
    res += a[mi];
    a[mi] = -1, b[mi] = -1, c[mi] = -1;
    mi = max_element(b.begin(), b.end()) - b.begin();
    res += b[mi];
    a[mi] = -1, b[mi] = -1, c[mi] = -1;
    mi = max_element(c.begin(), c.end()) - c.begin();
    res += c[mi];
    a[mi] = -1, b[mi] = -1, c[mi] = -1;
    chmax(ans, res);
    return;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    ans = 0;
    get(a, b, c);
    get(a, c, b);
    swap(a, b);
    get(a, b, c);
    get(a, c, b);
    swap(c, a);
    get(a, b, c);
    get(a, c, b);
    cout << ans << "\n";
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