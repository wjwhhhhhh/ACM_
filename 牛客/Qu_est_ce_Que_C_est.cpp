#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl;
using namespace std;
using i64 = long long;
const int N = 5100, M = 998244353;
long long qmi(long long k, long long p = M - 2, long long P = M)
{
    long long res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % P;
        k = k * k % P;
        p >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, m;
    cin >> n >> m;
    array<i64, 2 * N> last;
    fill(last.begin(), last.end(), 1);
    for (int i = 1; i < n; i++)
    {
        array<i64, 2 *N> ing = {0};
        i64 res = 0;
        for (int i = 0; i <= m; i++)
        {
            res = (res + last[2 * m - i]) % M;
            ing[i] = res;
        }
        i64 cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cnt = (cnt + last[i]) % M;
        }
        for (int i = m; i <= 2 * m; i++)
            ing[i] = res;

        for (int i = m; i < 2 * m; i++)
        {
            ing[i] = (ing[i] + cnt) % M;
            cnt = (cnt % M - last[i - m] + M) % M;
        }
        swap(last, ing);
    }
    i64 ans = 0;
    // for (int i = 0; i <= 2 * m; i++)
    //     cout << last[i] << endl;
    for (int i = 0; i <= 2 * m; i++)
        ans = (ans + last[i]) % M;
    cout << ans << endl;
    return 0;
}