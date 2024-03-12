#include <algorithm>
#include <cstring>
#include <iostream>
// #define int long long
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int sum = 0;
        for (int i = 1; i <= 3; i++)
        {
            int tem = read();
            if (tem & 1)
                sum += i;
        }
        if (sum & 1)
            puts("1");
        else
            puts("0");
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}