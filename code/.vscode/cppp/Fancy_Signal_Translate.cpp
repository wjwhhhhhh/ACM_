#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
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
string tem;
int n;
set<string> mp;
bool check(int x)
{
    // cout << x << endl;
    mp.clear();
    string ans;
    for (int i = x; i <= n; i++)
    {
        ans = tem.substr(i - x + 1, x);
        mp.insert(ans);
    }
    // cout << mp.size() << endl;
    return mp.size() == (1 << x);
}
signed main()
{
    cin >> tem;
    int l = 1, r = tem.size();
    n = tem.size();
    tem = " " + tem;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (!check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    // check(1);
    cout << l << endl;
    return 0;
}