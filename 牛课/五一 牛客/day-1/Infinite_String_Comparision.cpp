#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
#define endl '\n'
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    string a, b;
    while (cin >> a >> b)
    {
        int ans = -1;
        if (a.size() < b.size())
            swap(a, b), ans = 1;
        a = a + a;
        while (b.size() < a.size())
            b = b + b;
        int fl = 0;
        fir(i, 0, a.size() - 1)
        {
            if (a[i] > b[i])
            {
                fl = -1;
                break;
            }
            else if (a[i] < b[i])
            {
                fl = 1;
                break;
            }
        }
        if (fl == 0)
            cout << "=" << endl;
        else if (fl == ans)
            cout << ">" << endl;
        else
            cout << "<" << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}