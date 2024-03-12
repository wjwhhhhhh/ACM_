#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, h;
    cin >> a >> h; //攻击力血量
    vector<vector<int> > dp(a + 1, std::vector<int> (h + 1, 1e9)); //防御攻击
    dp[0][1] = 0;
    for (int i = 0; i <= a; i++)for (int j = 1; j <= h; j++)
        {
            if (i)dp[i][j] = min(dp[i][j], dp[i - 1][j] + (h + (j - 1)) / j * (a - (i - 1)));
            if (j > 1)dp[i][j] = min(dp[i][j], dp[i][j - 1]+(h + j - 2) / (j - 1) * (a - i));
        }
    int ans = 1e9;
    for (int j = 1; j <= h; j++)ans = min(ans, dp[a][j]);
    cout << ans << endl;
    return 0;
}