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
    int n, w, k;
    cin >> n >> w >> k;
    vector<pair<int, int>> cnt;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        cnt.push_back({a, b});
    }
    sort(cnt.begin(), cnt.end());
    vector<int> tem;
    for (int j = 0; j < n; j++)
        tem.push_back(cnt[j].second);
    sort(tem.rbegin(), tem.rend());
    i64 res = 0;
    i64 ans = 0;
    for (int j = 0; j < k; j++)
    {
        res += tem[j];
    }
    chmax(ans, res);
    vector<i64> dp(w + 1);
    for (int i = 0; i < n - k; i++)
    {
        for (int j = w; j >= cnt[i].first; j--)
        {
            chmax(dp[j], dp[j - cnt[i].first] + cnt[i].second);
        }
        vector<int> tem;
        for (int j = i + 1; j < n; j++)
            tem.push_back(cnt[j].second);
        sort(tem.rbegin(), tem.rend());
        i64 res = dp[w];
        for (int j = 0; j < k; j++)
        {
            res += tem[j];
        }
        chmax(ans, res);
    }
    cout << ans << endl;
    return 0;
}