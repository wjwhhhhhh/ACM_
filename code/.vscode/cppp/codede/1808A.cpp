#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#define int long long
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
int dfs(int x)
{
    set<int> ch;
    ch.clear();
    while (x)
    {
        ch.insert(x % 10);
        x /= 10;
    }
    // cout << (*ch.rbegin()) << endl;
    return (*ch.rbegin()) - (*ch.begin());
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int l = read(), r = read();
        int time = 110;
        int res = -1, cnt;
        while (time-- && l <= r)
        {
            int tem = dfs(l);
            if (tem > res)
                res = tem, cnt = l;
            l++;
        }
        cout << cnt << '\n';
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}