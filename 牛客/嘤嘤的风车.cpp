#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;
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
const int N = 11;
char mp[8 << N][8 << N];
void sx(int a, int b, int x, int y)
{
    for (int i = a, j = b; i <= x && j <= y; i++, j++)
    {
        mp[i][j] = '*';
    }
}
void zs(int a, int b, int x, int y) //
{
    for (int i = a, j = b; i >= x && j <= y; i--, j++)
    {
        mp[i][j] = '*';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= (4 << n) + 1; i++)
        for (int j = 1; j <= (4 << n) + 1; j++)
            mp[i][j] = ' ';

    int x = (2 << n) + 1, y = x;
    for (int i = 1; i <= (4 << n) + 1; i++)
        mp[x][i] = '*', mp[i][y] = '*';
    int m = n;
    for (int n = 1; n <= m; n++)
    {
        if (n & 1)
        {
            sx(x - (2 << n), y, x - (1 << n), y + (1 << n));
            zs(x, y, x - (1 << n), y + (1 << n));
            sx(x, y, x + (1 << n), y + (1 << n));
            zs(x + (1 << n), y + (1 << n), x, y + (2 << n));
            sx(x + (1 << n), y - (1 << n), x + (2 << n), y);
            zs(x + (1 << n), y - (1 << n), x, y);
            sx(x - (1 << n), y - (1 << n), x, y);
            zs(x, y - (2 << n), x - (1 << n), y - (1 << n));
        }
        else
        {
            sx(x - (1 << n), y - (1 << n), x, y);
            zs(x - (1 << n), y - (1 << n), x - (2 << n), y);
            sx(x - (1 << n), y + (1 << n), x, y + (2 << n));
            zs(x, y, x - (1 << n), y + (1 << n));
            sx(x, y, x + (1 << n), y + (1 << n));
            zs(x + (2 << n), y, x + (1 << n), y + (1 << n));
            sx(x, y - (2 << n), x + (1 << n), y - (1 << n));
            zs(x + (1 << n), y - (1 << n), x, y);
        }
    }
    for (int i = 1; i <= (4 << n) + 1; i++)
    {
        for (int j = 1; j <= (4 << n) + 1; j++)
            cout << mp[i][j];
        cout << '\n';
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}