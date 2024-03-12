#include <algorithm>
#include <cstring>
#include <iostream>
#define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 110;
typedef long long LL;
typedef pair<int, int> PII;
int f[N][N];
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int n = read();
    for (int i = 1; i <= n; i++)
        w[i] = read(), w[i + 1] = w[i];
    n *= 2;
    fir(i, 1, i + 2 <= n) f[i][i + 2] = w[i] * w[i + 1] * w[i + 2];
    return 0;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}