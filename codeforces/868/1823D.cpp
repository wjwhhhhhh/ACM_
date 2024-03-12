#include <bits/stdc++.h>
using namespace std;
 #define int long long
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
int a[22], b[22];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        bool fl = true;
        int n, k;
        cin >> n >> k;
        fir(i, 1, k) cin >> a[i];
        fir(i, 1, k) cin >> b[i];
        string ans = "";
        if (a[1] < b[1])
            fl = false;
        for (int i = 1; i <= b[1] - 2&&fl; i++)
            ans += 'a';
        ans += "zy";
        int l = 0;
        for (int i = b[1] + 1; i <= a[1]&&fl; i++, l++)
        {
            if (l % 3 == 0)
                ans += 'a';
            else if (l % 3 == 1)
                ans += 'z';
            else
                ans += 'y';
        }
        for (int i = 2; i <= k&&fl; i++)
        {
            if (a[i] - a[i - 1] < b[i] - b[i - 1])
                fl = false;
            else
            {
                for (int j = 0; j < b[i] - b[i - 1]; j++)
                    ans += (char)(i - 1 + 'a');
                for (; ans.size() < a[i]; l++)
                {
                    if (l % 3 == 0)
                        ans += 'a';
                    else if (l % 3 == 1)
                        ans += 'z';
                    else
                        ans += 'y';
                }
            }
        }
        for (; ans.size() < n; l++)
        {
            if (l % 3 == 0)
                ans += 'a';
            else if (l % 3 == 1)
                ans += 'z';
            else
                ans += 'y';
        }
        if (!fl)
            cout << "NO" << endl;
        else
            cout << "YES" << endl << ans << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}