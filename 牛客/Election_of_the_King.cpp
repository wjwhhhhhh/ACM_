#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl;
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    array<int, 30> last = {0};
    int ans = 0;
    for (int i = -m; i <= m; i++)
        for (int j = -m; j <= m; j++)
        {
            if (i + j >= 0)
                last[min({j, j + i}) + 10]++;
        }
    for (int i = -m + 10; i <= m + 10; i++)
    {
        cout << last[i] << endl;
    }
    return 0;
}