#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 10;
int dp[N], w[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int ans = 0;
    for (int j = N-1000; j < N; j++)
    {
        unordered_set<int> has;
        for (int i = 1; i < j; i++)
            has.insert(N / i);
        ans = max(ans, (int)has.size());
    }
    cout << ans << endl;
    return 0;
}
