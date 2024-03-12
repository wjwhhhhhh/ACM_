#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int M = 1e9;
long long qmi(long long k, long long p = M - 2)
{
    long long res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % M;
        k = k * k % M;
        p >>= 1;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    cout << n * qmi(n - 1, m - 1) % M << endl;
    return 0;
}