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
string tem;
int check(char x)
{
    int ans = 0;
    int l = 0;
    for (int i = 0; i < tem.size(); i++)
    {
        if (tem[i] == x)
        {
            // cout << l;
            if (l == 0)
                ans = max(ans, 0);
            else
                ans = max(ans, __lg(l) + 1);
            l = 0;
        }
        else
            l++;
    }
    if (l == 0)
        ans = max(ans, 0);
    else
        ans = max(ans, __lg(l) + 1);
    // cout << ans;
    return ans;
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
        cin >> tem;
        int sum = 0x3f3f3f3f;
        for (int i = 0; i < 26; i++)
            sum = min(sum, check(i + 'a'));
        cout << sum << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}