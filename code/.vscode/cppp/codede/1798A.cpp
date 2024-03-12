#include <algorithm>
#include <cstring>
#include <iostream>
// #define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef pair<int, int> PII;
const int N = 110;
int a[N], b[N];
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
        int n = read();
        bool fl = true;
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 1; i <= n; i++)
            b[i] = read();
        fir(i, 1, n - 1)
        {
            if (a[i] > a[n])
                swap(a[i], b[i]);
            else if (b[i] > b[n])
                swap(a[i], b[i]);
        }
        fir(i, 1, n - 1)
        {
            if (a[i] > a[n])
                fl = false;
            if (b[i] > b[n])
                fl = false;
        }
        if (fl)
            puts("YES");
        else
            puts("NO");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}