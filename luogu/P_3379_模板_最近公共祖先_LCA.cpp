#include <algorithm>
#include <cstring>
#include <iostream>
// #define int long long
// #define int __int128
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
const int N = 5e5 + 10, M = 2 * N, k = 30;
int n, m, s;
int h[N], ne[M], e[M], idx = 1;
int dfs[2 * N], po[2 * N], ti = 0;
int f[2 * N][k], lg[2 * N];
int map[2 * N];
void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs2(int u, int fa)
{
    dfs[++ti] = u, po[u] = ti, map[po[u]] = u;
    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            dfs2(j, u);
            dfs[++ti] = u;
        }
    }
}
int op(int x, int y)
{
    if (po[x] < po[y])
        return x;
    else
        return y;
}
void init()
{
    fir(i, 1, ti) f[i][0] = dfs[i];
    fir(i, 1, k - 1)
    {
        fir(j, 1, ti + 1 - (1 << i))
        {
            f[j][i] = op(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
        }
    }
}
int lca(int l, int r)
{
    if (r < l)
        swap(l, r);
    cout << l << " " << r << endl;
    int len = r - l + 1;
    int re = lg[len];
    int tem = op(f[l][re], f[r - (1 << re) + 1][re]);
    return map[po[tem]];
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    n = read(), m = read(), s = read();
    fir(i, 1, n - 1)
    {
        int a = read(), b = read();
        add(a, b), add(b, a);
    }
    dfs2(s, -1);
    lg[0] = -1;
    for (int i = 1; i < 2 * N; i++)
        lg[i] = lg[i >> 1] + 1;
    init();
    fir(i, 1, m)
    {
        int a = read(), b = read();
        cout << lca(po[a], po[b]) << endl;
    }
    return 0;
}