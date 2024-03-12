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
const int N = 1e5 + 10;
int g[2][N];
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int n = read();
        int k = 1, r = 2 * n - 2, l = 1;
        g[0][1] = 2 * n, g[1][n] = r = 2 * n - 1;
        fir(i, 1, n)
        {
            g[k % 2][i] = l++;
            k++;
        }
        k = 1;
        fir(i, 2, n)
        {
            g[k % 2][i] = l++;
            k++;
        }
        for (int i = 0; i < 2; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << g[i][j] << " ";
            puts("");
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}