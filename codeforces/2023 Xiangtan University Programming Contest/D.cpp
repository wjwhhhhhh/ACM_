#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int a[N];
void solves()
{

    int n, m;
    cin >> n >> m;
    std::vector<string> v(n + 5);
    for (int i = 1; i <= n; i++)cin >> v[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (auto j : v[i])if (j == '@')ans++;
    }
    cout << ans / 2 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--)
    {
        solves();
    }
    return 0;
}