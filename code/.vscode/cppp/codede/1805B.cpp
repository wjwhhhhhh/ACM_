#include <algorithm>
#include <cstring>
#include <iostream>
// #define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int map[26];
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        met(map, -1);
        int n = read();
        string tem, a;
        cin >> tem;
        for (int i = 0; i < tem.size(); i++)
            map[tem[i] - 'a'] = i;
        a = tem;
        sort(a.begin(), a.end());
        char ch = a[0];
        string tr = ch + tem.substr(0, map[ch - 'a']) + tem.substr(map[ch - 'a'] + 1, tem.size() - map[ch - 'a'] - 1);
        cout << tr << endl;
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}