#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
// #define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
typedef long long LL;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
typedef pair<int, int> PII;
map<int, int> cy;
vector<int> cu, a;
vector<vector<int>> df;
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
        cy.clear();
        cu.clear();
        df.clear();
        bool fl = true;
        int m = read();
        fir(i, 1, m)
        {
            int n = read();
            a.clear();
            fir(j, 1, n)
            {
                int tem = read();
                cy[tem] = i;
                a.push_back(tem);
            }
            df.push_back(a);
        }
        fir(i, 1, m) for (auto j : df[i - 1])
        {
            if (cy[j] == i)
            {
                cu.push_back(j);
                break;
            }
        }
        if (cu.size() == m)
        {
            for (auto i : cu)
                cout << i << " ";
            puts("");
        }
        else
            puts("-1");

        // cout << cu.size();
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}