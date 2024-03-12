#include <algorithm>
#include <cstring>
#include <iostream>
#define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 1e5 + 10;
int a[N];
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
    int t = read();
    while (t--)
    {
        int n = read();
        fir(i, 0, n - 1) a[i] = read();
        if (n & 1)
        {
            fir(i, 0, n - 4)
            {
                if (i & 1)
                    cout << -1 * a[i ^ 1] << " ";
                else
                    cout << a[i ^ 1] << " ";
            }

            if (a[n - 2] + a[n - 3] == 0)
            {
                cout << -2 * a[n - 1] << " " << -1 * a[n - 1] << " " << a[n - 3];
            }
            else
                cout << -1 * a[n - 1] << " " << -1 * a[n - 1] << " " << a[n - 3] + a[n - 2];
        }
        else
        {
            fir(i, 0, n - 1)
            {
                if (i & 1)
                    cout << -1 * a[(i ^ 1)] << " ";
                else
                    cout << a[(i ^ 1)] << " ";
            }
        }
        puts("");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}