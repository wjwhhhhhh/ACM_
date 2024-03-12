#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 3e5 + 10;
vector<int> a[N];
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
signed main()
{
    // freopen("test.txt", "r", stdin);
    int t = read();
    while (t--)
    {
        int n = read(), m = read();
        fir(j, 1, m) a[j].clear();
        fir(i, 1, n) fir(j, 1, m)
        {
            int tem = read();
            a[j].push_back(tem);
        }
        fir(i, 1, m) sort(a[i].begin(), a[i].end());
        int res = 0, sum = 0;
        fir(i, 1, m)
        {
            sum = 0;
            for (int j = 1; j < a[i].size(); j++)
            {
                sum += j * (a[i][j] - a[i][j - 1]);
                res += sum;
            }
            // cout << sum << endl;
        }
        cout << res << "\n";
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}