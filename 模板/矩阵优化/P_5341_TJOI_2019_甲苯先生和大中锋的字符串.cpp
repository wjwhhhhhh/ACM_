#include <bits/stdc++.h>
// #define int long long
// #define int __int128
using namespace std;
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
vector<int> a[26], b[26];
int k, res;
string tem;
void check(vector<int> a, int l)
{
    if (a.size() < k)
        return;
    if (a.size() == k)
        res = max(res, l);
    for (int i = 0; i < 26; i++)
        b[i].clear();
    for (auto i : a)
    {
        if (i + 1 < tem.size())
            b[tem[i + 1] - 'a'].push_back(i + 1);
    }
    for (int i = 0; i < 26; i++)
        check(b[i], l + 1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        res = -1;
        for (int i = 0; i < 26; i++)
            a[i].clear();
        cin >> tem;
        cin >> k;
        for (int i = 0; i < tem.size(); i++)
            a[tem[i] - 'a'].push_back(i);
        for (int i = 0; i < 26; i++)
            check(a[i], 0);
        cout << res << '\n';
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}