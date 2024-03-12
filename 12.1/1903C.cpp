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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<i64> dp(n + 2);
    dp[n + 1] = 0;
    vector<i64> s(n + 1);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    priority_queue<i64> st;
    st.push(s[n]);
    for (int i = n; i; i--)
    {
        dp[i] = st.top() - s[i - 1];
        st.push(s[n] - s[i - 1] + dp[i] + s[i - 1]);
    }
    cout << dp[1] << endl;
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