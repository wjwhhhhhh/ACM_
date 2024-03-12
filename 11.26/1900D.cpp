#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = __int128;
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
const int N = 1e5 + 10;
i64 s[N];
i64 idx[N];
void print(__int128 num)
{ // 递归调用，实现从高位向低位输出
    if (num > 9)
        print(num / 10);
    cout << char(num % 10 + '0');
}
void solve()
{
    memset(s, 0, sizeof s);
    memset(idx, 0, sizeof idx);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        idx[a[i]]++;
    }
    for (int i = 1; i < N; i++)
    {
        s[i] = s[i - 1] + idx[i];
    }
    __int128 ans = 0;
    vector<__int128> dp(N, 0);
    for (int i = 1; i < N; i++)
    {
        i64 sum = 0, qian = 0;
        for (int j = i; j < N; j += i)
        {
            dp[i] += idx[j] * (idx[j] - 1) * (idx[j] - 2) / 6;
            dp[i] += (idx[j] * (idx[j] - 1) / 2) * (s[N - 1] - s[j]);
            dp[i] += qian * idx[j] * (s[N - 1] - s[j]);
            dp[i] += qian * (idx[j] * (idx[j] - 1) / 2);
            qian += idx[j];
        }
    }
    for (int i = N - 1; i > 0; i--)
    {
        for (int j = i + i; j < N; j += i)
        {
            dp[i] -= dp[j];
        }
    }
    for (int i = 0; i < N; i++)
        ans += 1ll * dp[i] * i;
    print(ans);
    cout << '\n';
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