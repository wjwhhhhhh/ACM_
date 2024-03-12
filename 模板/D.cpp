#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
const int N = 1e5 + 10;
int dp[N][210];
int w[210] int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> siz(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> siz[i] >> w[i];
    vector<int> s(m);
    for (int i = 0; i < m; i++)
        cin >> s[i];

    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i < m; i++)
        {
            if (siz[j] > s[i])
                continue;
            dp[i][j] = w[j] + w[siz[j] - s[i]];
        }
    }

    return 0;
}