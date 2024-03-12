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
const int N = 1e4 + 10, M = 2 * N;
int f[N][2];
int w[N];
bool st[N];
int h[N], e[M], ne[M], idx = 1;
void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
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
void dfs(int x)
{
    int res = 0, sum = 0;
    for (int i = h[x]; i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        res += max(f[j][1], f[j][0]), sum += f[j][0];
    }
    f[x][1] = sum + w[x], f[x][0] = res;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int n = read();
    fir(i, 1, n) w[i] = read();
    fir(i, 1, n - 1)
    {
        int a = read(), b = read();
        add(b, a);
        st[a] = true;
    }
    int root;
    fir(i, 1, n) if (!st[i]) root = i;
    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}