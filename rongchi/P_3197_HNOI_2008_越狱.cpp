#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
const int M = 998244353;
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
    // freopen("test.txt", "r", stdin);
    LL n, k;
    cin >> n >> k;
    auto ans = qmi(2, k);
    ans = qmi(ans - 1, k);
    cout << (ans + M) % M;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}