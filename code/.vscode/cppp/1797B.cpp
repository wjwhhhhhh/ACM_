#include <algorithm>
#include <cstring>
#include <iostream>
// #define int long long
//  #define int __int128
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
const int N = 1e3 + 10;
int g[N][N];
int n, m;
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        n = read(), m = read();
        int sum = 0;

        fir(i, 1, n) fir(j, 1, n) g[i][j] = read();
        fir(i, 1, n) fir(j, 1, n)
        {
            if (g[i][j] != g[n + 1 - i][n + 1 - j])
            {
                sum++;
                g[i][j] = g[n + 1 - i][n + 1 - j];
            }
        }
        if (sum > m)
            puts("NO");
        else if (n % 2 == 0 && (m - sum) & 1)
            puts("NO");
        else
            puts("YES");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}