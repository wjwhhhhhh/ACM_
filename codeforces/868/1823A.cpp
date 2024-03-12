#include <algorithm>
#include <cstring>
#include <iostream>
#define fir(i, a, b) for (int i = a; i <= b; i++)
// #define int long long
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
void solve()
{
    int n, t;
    cin >> n >> t;
    int k = -1;
    for (int i = 0; i <= n / 2; i++)
        if (!i && n * (n - 1) / 2 == t)
        {
            k = 0;
            break;
        }
        else if (i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2 == t)
        {
            k = i;
            break;
        }
    if (k == -1)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (int i = 1; i <= k; i++)
            cout << 1 << ' ';
        for (int i = k + 1; i <= n; i++)
            cout << -1 << ' ';
        cout << endl;
    }
}

signed main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}