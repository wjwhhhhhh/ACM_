#pragma GCC optimize(3, "Ofast", "inline")
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
const int M = 2e7 + 10;
vector<int> q, s(M + 1), idx;
void euler_function(i64 x)
{
    vector<int> st(x + 1);
    st[1] = true;
    s[1] = 1;
    for (int i = 2; i <= x; i++)
    {
        if (!st[i])
            q.push_back(i), s[i] = i;
        for (int j = 0; q[j] <= x / i; j++)
        {
            s[q[j] * i] = q[j];
            st[q[j] * i] = true;
            if (i % q[j] == 0)
            {
                break;
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    euler_function(M);
    vector<int> a(n);
    vector<int> c(M);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> div, siz;
        int x = a[i];
        if (x == 1)
        {
            c[x]++;
            continue;
        }
        while (x > 1)
        {
            int tmp = 0, cnt = s[x];
            while (x % cnt == 0)
            {
                tmp++;
                x /= cnt;
            }
            div.push_back(cnt), siz.push_back(tmp);
        }
        function<void(int, int)> dfs = [&](int idx, int cnt) {
            if (idx == div.size())
            {
                c[cnt]++;
                return;
            }
            for (int i = 0; i <= siz[idx]; i++)
            {
                dfs(idx + 1, cnt);
                cnt *= div[idx];
            }
        };
        dfs(0, 1);
    }
    vector<i64> dp(M);
    i64 ans = 0;
    dp[1] = n;
    // cerr << "ok" << endl;
    for (int i = 1; i < M; i++)
    {
        chkmax(ans, dp[i]);
        for (auto j : q)
        {
            if (1ll * j * i >= M)
                break;
            chkmax(dp[j * i], dp[i] + c[j * i] * (1ll * j * i - i));
        }
    }
    cout << ans << endl;
    return 0;
}