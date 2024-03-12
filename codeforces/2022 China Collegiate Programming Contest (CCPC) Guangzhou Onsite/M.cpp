#include <bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e9 + 7, K = 105,mod=M;
int c[K][K];
int n, m, k;
int a[K];
int po[K];
int dp[K][K][K];
bool st[K][K][K];
int dfs(int cur, int s, int lv) {
    if (lv < 0)return 0;
    if (cur < 0)return lv == 0;
    int s1 = k / 2, s0 = k - s1;
    if (((1ll << cur + 1) - 1) * s0 * s1 < lv)return 0;
    if (st[cur][s][lv])return dp[cur][s][lv];
        st[cur][s][lv]=true;
    int res = 0;
    if (a[cur] == 1) {
        for (int i = 0; i <= s; i++) {
            for (int j = 0; j <= k - s; j++) {
                int val = 1ll * (k - i - j) * (i + j) * (1ll << cur);
                int t = c[s][i] * c[k - s][j] % mod;
                res += t * dfs(cur - 1, i, lv - val) % mod;
                res %= mod;
            }
        }
    }
    else {
        for (int i = 0; i <= 0; i++) {
            for (int j = 0; j <= k - s; j++) {
                int val = 1ll * (k - i - j) * (i + j) * (1ll << cur);
                int t = c[s][i] * c[k - s][j] % mod;
                res += t * dfs(cur - 1, s, lv - val) % mod;
                res %= mod;
            }
        }
    }
    return dp[cur][s][lv] = res;
}
void solves()
{
    cin >> n >> m >> k;
    int t = m, id = -1;
    while (t)a[++id] = t % 2, t /= 2;
    cout << dfs(id, k, n) << endl;
    return ;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    c[0][0] = 1;
    c[1][0] = c[1][1] = 1;
    for (int i = 2; i <= 100; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= 100; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    po[0] = 1;
    for (int i = 1; i <= 100; i++)po[i] = po[i - 1] * 2ll;
    solves();
    return 0;
}