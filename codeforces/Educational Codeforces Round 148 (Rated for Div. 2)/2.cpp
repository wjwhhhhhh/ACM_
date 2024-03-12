#include <bits/stdc++.h>
using namespace std;
void solves()
{
    int n, k;
    cin >> n >> k;
    vector<long long> f(n + 5), q(n + 5);
    for (int i = 1; i <= n; i++)cin >> f[i];
    sort(f.begin()+1, f.begin()+n+1);
    for (int i = 1; i <= n; i++)q[i] = q[i - 1] + f[i];
    long long ans = 0;
    for (int i = 0; i <= k; i++)
    {
        if (2 * (k - i) + i > n)continue;
        ans = max(ans, q[n - i] - q[2 * (k - i)]);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solves();
    }
    return 0;
}