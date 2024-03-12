#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int cnt[1 << 21];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x;
    cin >> n >> m >> x;
    std::vector<std::vector<int> > a(n, std::vector<int> (m));
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    i64 ans = 0;
    if (n <= m)
    {
        for (int i = 0; i < n; i++)for (int j = i + 1; j < n; j++)
            {   for (int k = 0; k < m; k++)
                {
                    ans += cnt[x ^ a[i][k] ^ a[j][k]];
                    cnt[a[i][k]^a[j][k]]++;
                }
                for (int k = 0; k < m; k++)
                {
                    cnt[a[i][k]^a[j][k]]--;
                }
            }
    }
    else
    {
        for (int i = 0; i < m; i++)for (int j = i + 1; j < m; j++)
            {   for (int k = 0; k < n; k++)
                {
                    ans += cnt[x ^ a[k][i] ^ a[k][j]];
                    cnt[a[k][i]^a[k][j]]++;
                }
                for (int k = 0; k < n; k++)
                {
                    cnt[a[k][i]^a[k][j]]--;
                }
            }
    }
    cout << ans << endl;
    return 0;
}