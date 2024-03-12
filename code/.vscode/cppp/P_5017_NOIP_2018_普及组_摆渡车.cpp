#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long
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
const int N = 510, M = 110;
int n, m;
int f[N][M];
int w[N];
int q_w[N];
signed main()
{
    // freopen("test.txt", "r", stdin);
    n = read(), m = read();
    met(f, 0x7f);
    fir(i, 1, n) w[i] = read();
    sort(w + 1, w + 1 + n);
    fir(i, 1, n) q_w[i] = q_w[i - 1] + w[i];
    // fir(i, 0, m) f[0][i] = 0;
    f[0][0] = 0;
    w[0] = -0x3f3f3f3f3f3f3f;
    for (int i = 0; i < n; i++)
    {
        int ma = min(m - 1, w[i + 1] - w[i]);
        for (int j = 0; j <= ma; j++)
        {
            int tem = w[i] + j + m;
            for (int k = i + 1; k <= n; k++)
            {
                int tem2 = max(0ll, tem - w[k]);
                f[k][tem2] = min(f[k][tem2], f[i][j] + (k - i) * (tem2 + w[k]) - (q_w[k] - q_w[i]));
            }
        }
    }
    int res = f[n][0];
    fir(i, 1, m - 1) res = min(res, f[n][i]);
    print(res);
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}