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
map<char, int> st, sh;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        st.clear(), sh.clear();
        bool fl = false;
        int n;
        cin >> n;
        string tem;
        cin >> tem;
        for (auto i : tem)
            st[i]++;
        for (auto i : st)
        {
            if (i.second > n / 2)
                fl = true;
        }
        if (n & 1)
            fl = true;
        if (fl)
            cout << "-1" << endl;
        else
        {
            for (int i = 0; i < n / 2; i++)
                if (tem[i] == tem[n - i - 1])
                    sh[tem[i]]++;
            int mmax = 0, same = 0;
            for (auto i : sh)
            {
                same += i.second;
                mmax = max(mmax, i.second);
            }
            cout << max((same + 1) / 2, mmax) << endl;
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}