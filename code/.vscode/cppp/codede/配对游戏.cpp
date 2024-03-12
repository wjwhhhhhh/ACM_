#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
int f[2010];
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int n = read();
    int res = 0, sum = 0;
    f[0] = 1, f[1] = 1;
    fir(i, 2, n + 3) f[i] = f[i - 1] + f[i - 2];
    if (n & 1)
    {
        for (int i = 1; i <= n; i += 2)
        {
            for (int j = 1; j + i - 1 <= n; j += 2)
            {
                int tem = f[(j - 1) / 2] * f[(n - j - i + 1) / 2];
                sum += tem;
                res += i * tem;
            }
        }
    }
    else
    {
        for (int i = 2; i <= n; i += 2)
        {
            for (int j = 1; j + i - 1 <= n; j += 2)
            {
                int tem = f[(j - 1) / 2] * f[(n - j - i + 1) / 2];
                sum += tem;
                res += i * tem;
            }
        }
    }
    cout << sum;
    double tem = 1.0 * res / (1.0 * sum);
    // printf("%.3lf", tem);
    //   freopen("CON", "r", stdin);
    //   system("pause");
    return 0;
}