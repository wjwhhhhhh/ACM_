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
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return a[x] < a[y]; });
    vector<int> l(n);
    vector<i64> s(n);
    s[0] = a[o[0]];
    for (int i = 1; i < n; i++)
        s[i] = s[i - 1] + a[o[i]];
    l[n - 1] = n - 1;
    for (int i = n - 2; ~i; i--)
    {
        if (s[i] < a[o[i + 1]])
            l[i] = i;
        else
            l[i] = l[i + 1];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[o[i]] = l[i];
    for (auto c : ans)
        cout << c << " ";
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