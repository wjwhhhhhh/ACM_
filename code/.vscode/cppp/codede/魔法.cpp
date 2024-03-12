#include <algorithm>
#include <cstring>
#include <iostream>
// #define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int M = 2510, N = 110;
struct edges
{
    int a, b, w;
} p[M];
int f[N][N], g[N][N];
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
int n, m, K;
void mul(int ans[N][N], int a[N][N], int b[N][N])
{
    int tem[N][N];
    met(tem, 0x3f);
    fir(k, 1, n) fir(i, 1, n) fir(j, 1, n)
    {
        tem[i][j] = min(tem[i][j], a[i][k] + a[k][j]);
    }
    memcpy(ans, tem, sizeof tem);
}
void qmi()
{
    while (K)
    {
        if (K & 1)
            mul(f, f, g);
        mul(g, g, g);
        K >>= 1;
    }
}
signed main()
{
    met(f, 0x3f);
    // freopen("test.txt", "r", stdin);
    n = read(), m = read(), K = read();
    fir(i, 1, n) f[i][i] = 0;
    fir(i, 1, m)
    {
        int a = read(), b = read(), c = read();
        f[a][b] = min(f[a][b], c);
        p[i] = {a, b, c};
    }
    fir(k, 1, n) fir(i, 1, n) fir(j, 1, n) f[i][j] = min(f[i][j], f[i][k], f[k][j]);
    memcpy(g, f, sizeof f);
    fir(i, 1, n) fir(j, 1, n) fir(k, 1, m) g[i][j] = min(g[i][j], g[i][p[k].a] + g[p[k].b][j] - p[k].w);
    qmi();
    cout << f[1][n];
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}