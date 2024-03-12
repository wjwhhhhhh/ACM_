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
void ask(int x, int y)
{
    cout << "? " << x << ' ' << y << endl;
    cout << endl;
}
void pri(int x, int y)
{
    cout << "! " << x + 1 << " " << y + 1 << endl;
    cout << endl;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        int a, b, c;
        cin >> n >> m;
        ask(1, 1);
        cin >> a;
        if (a + 1 > m)
        {
            ask(a + 1, 1);
            cin >> b;
            pri(a, b);
        }
        else if (a + 1 > n)
        {
            ask(1, a + 1);
            cin >> b;
            pri(b, a);
        }
        else
        {
            ask(1, a + 1);
            cin >> b;
            if (a == b)
            {
                ask(a + 1, 1);
                cin >> c;
                pri(a, c);
            }
            else
                pri(b, a);
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}