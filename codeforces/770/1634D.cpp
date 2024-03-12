#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define int __int128
// #define endl '\n'
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
int ans1, ans2, n;
int ask(int p, int a = ans1, int b = ans2)
{
    cout << "? " << a << " " << b << " " << p << endl;
    int tem;
    cin >> tem;
    return tem;
}
bool find()
{
    bool fl = true;
    int who, dist = -1, tem1 = -1, tem2;
    for (int i = 1; i <= n; i++)
    {
        if (i == ans1 || i == ans2)
            continue;
        tem2 = ask(i);
        if (tem1 != -1 && tem1 != tem2)
            fl = false;
        if (tem2 > dist)
        {
            dist = tem2, who = i;
        }
    }
    if (fl)
        return true;
    ans2 = who;
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans1 = 1, ans2 = 2;
        if (!find())
        {
            swap(ans2,ans1);
            find();
        }
        cout << "! " << ans1 << " " << ans2 << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}