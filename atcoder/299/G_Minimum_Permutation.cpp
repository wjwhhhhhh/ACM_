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
const int N = 2e5 + 10;
vector<int> wei[N];
map<int, int> st;
int f[N];
int d[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    fir(i, 1, n) cin >> f[i];
    fir(i, 1, n)
    {
        d[f[i]] = i;
        wei[f[i]].push_back(i);
    }
    fir(i, 1, m) st[d[i]] = i, reverse(wei[i].begin(), wei[i].end());
    fir(t, 1, m / 10 + 2) fir(i, 1, m)
    {
        // reverse(wei[i].begin(), wei[i].end());
        for (auto j : wei[i])
        {

            auto tem = st.lower_bound(j);
            // if (i == 3)
            //     cout << tem->first;
            if (tem->second >= i)
            {
                // cout << tem->second << " " << i;
                st.erase(d[i]);
                d[i] = j;
                st[j] = i;
            }
        }
        // for (auto i : st)
        // {
        //     cout << i.second << " ";
        // }
        // cout << endl;
    }
    for (auto i : st)
    {
        cout << i.second << " ";
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}