#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long
#define fir(i, a, b) for (int i = a; i < b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef pair<int, int> PII;
int f[5010][2];
int w[5010];
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int n = read();
    for (int i = 1; i <= n; i++)
        w[i] = read();
    f[1][0] = w[1], f[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i][1] = min(f[i - 1][1], f[i - 1][0]) + 1;
        if (w[i] >= w[i - 1])
        {
            f[i][0] = f[i - 1][0] + w[i] - w[i - 1];
        }
        else
        {
            f[i][0] = f[i - 1][0];
        }
    }
    cout << min(f[n][0], f[n][1]) << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}