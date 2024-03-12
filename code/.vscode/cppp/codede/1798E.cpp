#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
// #define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;

#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;

const int N = 3e5 + 10, M = N;

int a[N];
int f[N][2];
int ans[N];
int n;

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
    int t = read();
    while (t--)
    {
        n = read();
        memset(f, -0x3f, 8 * (n + 5));
        for (int i = 1; i <= n; i++)
            a[i] = read();
        f[n + 1][0] = 0, f[n + 1][1] = 0;
        int tem = f[n + 1][0];
        for (int i = n; i > 0; i--)
        {
            int j = i + a[i] + 1;
            f[i][1] = tem + 1;
            if (j <= n + 1)
            {
                f[i][0] = f[j][0] + 1;
                f[i][1] = max(tem, f[j][1]) + 1;
            }
            tem = max(f[i][0], tem);
        }
        // cout<<f[n][0];
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i] == f[i + 1][0])
                ans[i] = 0;
            else if (a[i] <= f[i + 1][1] || f[i + 1][0] >= 0)
                ans[i] = 1;
            else
                ans[i] = 2;
        }
        fir(i, 1, n - 1) cout << ans[i] << " ";
        puts("");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
} // 0 1 1