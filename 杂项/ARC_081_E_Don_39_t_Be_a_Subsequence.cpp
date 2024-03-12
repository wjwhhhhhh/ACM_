#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    string a;
    cin >> a;
    int n = a.size();
    a = " " + a;
    vector<array<int, 26>> dp(n + 2);
    fill(dp[n + 1].begin(), dp[n + 1].end(), n + 1);
    for (int i = n; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        if (i)
            dp[i][a[i] - 'a'] = i;
    }
    vector<i64> fr(n + 2, 1e9);
    fr[n + 1] = 1;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            chkmin(fr[i], fr[dp[i + 1][j]] + 1);
        }
    }
    vector<int> st(26);
    i64 len = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        if (!st[a[i] - 'a'])
        {
            chkmin(len, fr[i]);
            st[a[i] - 'a'] = true;
        }
    }
    bool fl = false;
    for (int j = 0; j < 26; j++)
    {
        if (!st[j])
        {
            fl = true;
            // while(1);
            string ans(1, (j + 'a'));
            assert(ans == "b");
            cout << ans;
            return 0;
        }
    }
    string ans;
    int ing = 0;
    while (ing != n + 1)
    {
        for (int j = 0; j < 26; j++)
        {
            if (fr[dp[ing + 1][j]] == len)
            {
                ans += char(j + 'a');
                ing = dp[ing + 1][j];
                break;
            }
        }
        len--;
    }
    cout << ans << endl;
    return 0;
}