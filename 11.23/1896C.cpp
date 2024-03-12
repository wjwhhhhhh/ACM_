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
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> o(n);
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return a[x] > a[y]; });
    vector<int> ans(n);
    priority_queue<int, vector<int>, greater<int>> st;
    for (int i = 0; i < n; i++)
        st.push(b[i]);
    for (int i = x - 1; i >= 0; i--)
    {
        ans[o[i]] = st.top();
        st.pop();
    }
    for (int i = n - 1; i >= x; i--)
    {
        ans[o[i]] = st.top();
        st.pop();
    }
    int ing = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > ans[i])
            ing++;
    }
    if (ing == x)
    {
        cout << "YES" << '\n';
        for (auto c : ans)
            cout << c << " ";
        cout << '\n';
    }
    else
        cout << "NO\n";
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