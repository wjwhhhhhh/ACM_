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
int ask(int x)
{
    cout << "? " << x << endl;
    int tem;
    cin >> tem;
    return tem;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    int l = 1, r = n;
    while (r - l != 1)
    {
        int mid = l + r >> 1;
        int t = ask(mid);
        if (t == 1)
            r = mid;
        else
            l = mid;
    }
    cout << "! " << l << endl;
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}