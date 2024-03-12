#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#define int long long
#define fir(i, a, b) for (int i = a; i < b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef pair<int, int> PII;
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
int fen_zhi(int l, int r)
{
    int res = 0;
    int mi = 0x3f3f3f3f;
    for (int i = l; i <= r; i++)
        mi = min(mi, w[i]);
    res += min(l - r + 1, mi);
    int s = l;
    for (int i = l; i <= r; i++)
    {
        w[i] -= mi;
        if (w[i] == 0)
            res += fen_zhi(s, i), s = i + 1;
    }
}
signed main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
        w[i] = read();
    cout << fen_zhi(1, n) << endl;
}