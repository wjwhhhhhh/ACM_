#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
void solve()
{
    int n, p;
    cin >> n >> p;
    priority_queue<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(p);
    }
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    i64 ans = p;
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return b[x] < b[y]; });
    int ing = 1;
    for (int i = 0; i < n; i++)
    {
        int j = o[i];
        if (b[j] >= p)
            continue;
        if (i + 1 <= ing)
        {
            i64 re = min(n - ing, a[j]);
            ans += b[j] * re;
            // cout << ans << endl;
            ing += re;
        }
        if (ing == n)
            break;
    }
    ans += 1ll * (n - ing) * p;
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