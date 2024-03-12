#include <bits/stdc++.h>
using namespace std;
void solves()
{
    int n;
    cin >> n;
    std::vector f(n + 2, std::vector<int>(m, inf));
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f0[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int ans = inf;
        swap(f0, f1);
        f0.clear();
        for (auto [j, x] : f1)
        {
            f0[j ^ a[i]] = min(f0[j ^ a[i]], x + (j == a[i] ? 0 : 1));
            ans = min(ans, x);
        }
        f0[0] = min(f0[0], ans + 1);
    }
    cout << f0[0] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        solves();
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}