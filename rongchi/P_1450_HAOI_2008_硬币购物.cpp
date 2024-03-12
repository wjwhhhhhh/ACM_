#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int dp[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    vector<int> c(4);
    for (int i = 0; i < 4; i++)
        cin >> c[i];
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 0; i < 4; i++)
        for (int j = c[i]; j < N; j++)
        {
            dp[j] += dp[j - c[i]];
        }
    while (n--)
    {
        vector<int> d(4);
        for (int i = 0; i < 4; i++)
            cin >> d[i];
        int s;
        cin >> s;
        int ans = 0;
        for (int i = 1; i < 1 << 4; i++)
        {
            int si = 0;
            int tem = s;
            for (int j = 0; j < 4; j++)
            {
                if (i >> j & 1)
                {
                    si++;
                    tem -= c[j] * (d[j] + 1);
                }
            }
            if (tem >= 0)
                ans += ((si & 1) ? 1 : -1) * dp[tem];
        }
        cout << dp[s] - ans << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}