#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
// #define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
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
const int N = 2010;
int f[N][N], g[N][N];
int n, t, s, e;
int idx = 1;
map<int, int> ct;
void mul(int ans[N][N], int a[N][N], int b[N][N])
{
    int tem[N][N];
    met(tem, 0x3f);
    fir(k, 1, idx - 1) fir(i, 1, idx - 1) fir(j, 1, idx) tem[i][j] =
        min(tem[ct[i]][ct[j]], a[ct[i]][ct[k]] + b[ct[k]][ct[j]]);
    memcpy(ans, tem, sizeof tem);
}
void qmi()
{
    fir(i, 1, idx - 1) f[i][i] = 0;
    while (n)
    {
        if (n & 1)
            mul(f, f, g);
        mul(g, g, g);
        n <<= 1;
    }
}
signed main()
{
    met(g, 0x3f);
    met(f, 0x3f);
    // freopen("test.txt", "r", stdin);
    n = read(), t = read(), s = read(), e = read();
    if (ct.find(s) == ct.end())
        ct[s] = idx++;
    if (ct.find(e) == ct.end())
        ct[e] = idx++;
    s = ct[s], e = ct[e];
    for (int i = 1; i <= n; i++)
    {
        int a = read(), b = read(), c = read();
        if (ct.find(a) == ct.end())
            ct[a] = idx++;
        if (ct.find(b) == ct.end())
            ct[b] = idx++;
        g[ct[a]][ct[b]] = g[ct[b]][ct[a]] = min(g[ct[a]][ct[b]], c);
    }
    qmi();
    cout << f[s][e];
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}