#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
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
int n, k, m;
int f[110][35];
int mi[110];
int cal(int S)
{
    met(f, 0);
    f[0][0] = 1;
    fir(i, 1, n) fir(j, 0, k - 1)  fir(x, 0, k - 1)
    {
        if ((x + x) % m != S)
            f[i][(j + x) % m] = (f[i][(j + x) % m] + f[i - 1][j]) % m;
    }
    return f[n][S];
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    n = read(), m = read(), k = read();
    mi[0] = 1;
    fir(i, 1, n) mi[i] = (mi[i] * k) % m;
    int res = mi[n], cnt = 0;
    fir(S, 0, k - 1) cnt = (cnt + cal(S)) % m;
    res = ((res + m) - cnt) % m;
    cout << res;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}