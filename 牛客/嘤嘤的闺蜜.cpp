#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define endl '\n'
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
const int N = 1e5 + 10;
int sum[N];
vector<int> b[N];
unordered_map<int, int> mp[N];
map<PII, int> ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int n, m, q;
    cin >> n >> m >> q;
    fir(i, 1, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        sum[b] += c;
        mp[b].insert({a, c});
    }
    while (q--)
    {
        int flag;
        cin >> flag;
        if (flag == 1)
        {
            int a;
            cin >> a;
            cout << sum[a] << endl;
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if (mp[a].size() > mp[b].size())
                swap(a, b);
            if (ans.find({a, b}) != ans.end())
            {
                cout << ans[{a, b}] << endl;
            }
            else
            {
                int su = sum[a] + sum[b];
                for (auto i : mp[a])
                {
                    auto x = i.first, y = i.second;
                    if (mp[b].find(x) != mp[b].end())
                    {
                        y = min(y, mp[b][x]);
                        su -= y;
                    }
                }
                cout << su << endl;
                ans.insert({{a, b}, su});
            }
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}