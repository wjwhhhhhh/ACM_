#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
int M;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n >> M;
    i64 ans = 2;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * ans % M;
    }
    cout << ans << endl;
    return 0;
}