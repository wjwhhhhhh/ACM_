#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 998244353;
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
int main()
{
    i64 a, b;
    cin >> a >> b;

    b = a + b;
    i64 si = 0;
    i64 ans = 1, p = qmi(2), in = 1;
    for (int i = 1; si + i < b; i *= 2)
    {
        si += i;
        in = (in * p) % M;
        // ans = (ans * qmi((1 - in + M) % M, num - a + 1, M)) % M;
        if (a > si + 2 * i - 1)
            continue;
        if (a >= si && a <= si + 2 * i - 1)
        {
            int num = min(si + 2 * i - 1, b - 1);
            ans = (ans * qmi((1 - in + M) % M, num - a + 1, M)) % M;
        }
        if (a < si)
        {
            int num = min(si + 2 * i - 1, b - 1);
            ans = (ans * qmi((1 - in + M) % M, num - si + 1, M)) % M;
        }
    }
    cout << ans << endl;
}