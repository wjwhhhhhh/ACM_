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
const int N = 310, M = 2 * N;
int f[N][N];
int w[N];
int h[N], e[M], ne[M], idx = 1;
typedef long long LL;
typedef pair<int, int> PII;
void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
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
int n, m;
void dfs(int root)
{
    f[root][1] = w[root];
    for (int i = h[root]; i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        for (int t = m; t >= 0; t--)
        {
            for (int k = 1; k <= m; k++)
            {
                if (t >= k + 1)
                    f[root][t] = max(f[root][t], f[root][t - k] + f[j][k]);
            }
        }
    }
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    n = read(), m = read();
    m++;
    fir(i, 1, n)
    {
        int a = read(), b = read();
        add(a, i);
        w[i] = b;
    }
    dfs(0);
    cout << f[0][m] << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}