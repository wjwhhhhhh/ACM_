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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> dp(100);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int z = j + 1; z < n; z++)
            {
                vector<int> cnt{a[i], a[j], a[z]};
                sort(cnt.begin(), cnt.end());
                dp[__gcd(cnt[0], cnt[1])]++;
            }
        }
    }
    for (int i = 1; i < 20; i++)
    {
        cout << dp[i] << " " << i << endl;
    }
    return 0;
}