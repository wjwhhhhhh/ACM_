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
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    auto huo = [&](int x, int y) {
        int idx = 0;
        while (x && x % y == 0)
        {
            idx++;
            x /= y;
        }
        return idx;
    };
    auto get = [&](int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == 1 && j == 1)
                {
                    dp[1][1] = huo(a[1][1], x);
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + huo(a[i][j], x);
                }
            }
        return dp[n][n];
    };
    auto lu = [&](int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
        vector<vector<int>> cnt(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (i == 1 && j == 1)
                {
                    dp[1][1] = huo(a[1][1], x);
                }
                else
                {
                    dp[i][j] = huo(a[i][j], x);
                    if (dp[i - 1][j] > dp[i][j - 1])
                    {
                        cnt[i][j] = 1;
                        dp[i][j] += dp[i][j - 1];
                    }
                    else
                    {
                        cnt[i][j] = 0;
                        dp[i][j] += dp[i - 1][j];
                    }
                }
            }
        vector<char> ans;
        int x1 = n, y = n;
        while (x1 != 1 || y != 1)
        {
            if (cnt[x1][y])
            {
                ans.push_back('R');
                y--;
            }
            else
            {
                x1--;
                ans.push_back('D');
            }
        }
        reverse(ans.begin(), ans.end());
        for (auto ch : ans)
            cout << ch;
        return;
    };
    bool fl = false;
    int dx, dy;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
            {
                fl = true;
                dx = i, dy = j;
            }
        }
    int a1 = get(2), a2 = get(5);
    if (fl && a1 > 1 && a2 > 1)
    {
        vector<char> ans;
        cout << 1 << endl;
        for (int i = 1; i < dx; i++)
            ans.push_back('D');
        for (int i = 1; i < n; i++)
            ans.push_back('R');
        for (int i = dx; i < n; i++)
            ans.push_back('D');
        for (auto ch : ans)
            cout << ch;
    }
    else if (a1 > a2)
    {
        cout << a2 << endl;
        lu(5);
    }
    else
    {
        cout << a1 << endl;
        lu(2);
    }
    return 0;
}