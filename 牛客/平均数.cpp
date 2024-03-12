#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, k;
    cin >> n >> k;
    int si = k - k / n * n;
    for (int i = 1; i <= n - si; i++)
        cout << k / n << " ";
    for (int i = n - si + 1; i <= n; i++)
        cout << k / n + 1 << " ";
    return 0;
}