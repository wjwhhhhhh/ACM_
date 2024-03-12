#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#define int long long
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
using namespace std;
const int N = 2e5 + 10;
typedef long long LL;
typedef pair<int, int> PII;
vector<int> a[N], b[N];
int n, k;
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
int find(vector<int> a[N])
{
    int res = 0;
    for (int i = 1; i < N; i++)
    {
        fir(j, 0, a[i].size() - 1)
        {
            int l, r, e = a[i][j];
            r = min(n, e + k - 1), l = max(r + 2, k);
            auto x = lower_bound(a[i].begin(), a[i].end(), l);
            auto y = lower_bound(a[i].begin(), a[i].end(), r);
            if (r == a[i].end() || *y > r)
                res += (y - x);
            else
                res += (y - x + 1);
        }
    }
    return res;
}
signed main()
{
    // freopen("test.txt", "r", stdin);
    int res = 0;
    n = read(), k = read();
    res = (n - k + 1) * (k / 2ll);
    fir(i, 1, n)
    {
        int tem = read();
        if (i & 1)
            a[tem].push_back(i);
        else
            b[tem].push_back(i);
    }
    res -= find(a) + find(b);
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}