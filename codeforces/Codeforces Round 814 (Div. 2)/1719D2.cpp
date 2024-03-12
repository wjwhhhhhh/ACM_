#include <bits/stdc++.h>
using namespace std;
void solves()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1), cn(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    map<int, int> mp;
    int tem = 0;
    mp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        tem ^= a[i];
        if (mp.find(tem) != mp.end())
            cn[i] = mp[tem] + 1;
        mp[tem] = i;
    }
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] + 1;
        if (cn[i] != 0)
        {
            f[i] = min(f[i], f[cn[i] - 1] + (i - cn[i]));
        }
    }
    cout << f[n] << '\n';
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