#include <algorithm>
#include <cstring>
#include <iostream>
#define fir(i, a, b) for (int i = a; i < b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 10;
int a[N], b[N], c[N];
typedef pair<int, int> PII;
int n, m;
bool st[N];
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
int sum = -0x3f3f3f3f;
void dfs(int shu, int time, int fen)
{
    if (shu >= n || time >= m)
    {
        // cout << shu << endl;
        sum = max(sum, fen);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            int tem = a[i] - (a[i] * 0.004) * (time + b[i]) - c[i] * 50;
            tem = max(tem, (int)(a[i] * 0.3));
            st[i] = true;
            dfs(shu + 1, time + b[i], fen + tem);
            st[i] = false;
        }
    }
}
int main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        met(st, 0);
        n = read(), m = read();
        for (int i = 1; i <= n; i++)
            a[i] = read(), b[i] = read(), c[i] = read();
        dfs(0, 0, 0);
        cout << sum << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}