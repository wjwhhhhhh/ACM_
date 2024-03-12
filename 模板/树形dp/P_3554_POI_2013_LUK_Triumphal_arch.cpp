#include <bits/stdc++.h>
// #define int long long
// #define int __int128
using namespace std;
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

const int N = 3e5 + 10;
int f[N];
int h[N], e[2 * N], ne[2 * N], idx = 1;
void add(int a, int b) // 添加一条边a->b
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u, int fa, int k)
{
    int s = 0;
    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            s++;
            dfs(j, i, k);
            f[u] += f[j];
        }
    }
    if (s == 0)
        f[u] = 1;
    else
        f[u] = max(0, f[u] - k) + 1;
}
bool check(int x)
{
    met(f, 0);
    dfs(1, -1, x);
    if (f[1] == 1)
        return true;
    else
        return false;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}