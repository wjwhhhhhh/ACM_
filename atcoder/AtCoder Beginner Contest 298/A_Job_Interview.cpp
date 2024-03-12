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
    int a[3] = {0};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;

    cin >> n;
    string tem;
    cin >> tem;
    for (auto i : tem)
        if (i == 'o')
            a[0]++;
        else if (i == 'x')
            a[1]++;
        else
            a[2]++;
    //cout << a[1];
    if (a[0] > 0 && a[1] == 0)
        puts("Yes");
    else
        puts("No");
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}