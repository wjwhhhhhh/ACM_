#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
#define endl '\n'
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
inline int read()
{
    char c = getchar();
    int x = 0, s = 1;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            s = -1;
        c = getchar();
    } // 是符号
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    } // 是数字
    return x * s;
}
void print(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}
const int M = 998244353, N = 1e6 + 10;
int qmi(int k, int p = M - 2)
{
    int res = 1;
    while (p)
    {
        if (p & 1)
            res = res * k % M;
        k = k * k % M;
        p >>= 1;
    }
    return res;
}
int f[2 * N], inv[2 * N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int n;
    f[1] = f[0] = 1;
    for (int i = 2; i < 2 * N; i++)
        f[i] = (f[i - 1] * i) % M;
    for (int i = 0; i < 2 * N; i++)
        inv[i] = qmi(f[i]);
    while (cin >> n)
    {
        int tem = (((2 * n + 1) % M) * (f[2 * n] * inv[n] % M) % M) * inv[n] % M;
        tem = qmi(tem);
        cout << tem << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}