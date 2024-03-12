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
const long long N = 1e12, M = 1e12 + 1, Q = 3e5 + 10;
;
typedef long long LL;
typedef pair<int, int> PII;
vector<PII> st;
vector<int> g[2];
int lm[Q], rm[Q];
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
    int t;
    cin >> t;
    while (t--)
    {
        string tem;
        cin >> tem;
        st.clear();

        int l = 0, r = tem.size() - 1;
        while (l < tem.size() && tem[l] == '0')
            l++;
        while (r >= 0 && tem[r] == '1')
            r--;
        if (l >= r)
            cout << "0" << endl;

        else
        {
            int res = 0;
            for (int i = l; i <= r; i++)
            {
                int x = i, y, si = 0;
                while (x <= r && tem[x] == '1')
                    x++, si++;
                y = x;
                while (y <= r && tem[y] == '0')
                    y++;
                st.push_back({si, y - i});
                i = y - 1;
            }
            // cout<<st[0].second;
            int su = st.size() - 1;
            fir(i, 0, st.size() - 1) lm[i + 1] = st[i].first, rm[i + 1] = st[i].second - st[i].first;
            fir(i, 1, st.size()) lm[i] += lm[i - 1];
            for (int i = st.size(); i > 0; i--)
                rm[i] += rm[i + 1];
            res = min(lm[su + 1] * M, rm[1] * M);
            fir(i, 0, su)
            {
                int tem = 0;
                if (st[i].first == 1)
                {
                    tem += (st[i].second - st[i].first) * N;
                }
                else
                    tem += (st[i].second - st[i].first) * M;
                tem += lm[i] * M + rm[i + 2] * M;
                res = min(tem, res);
            }
            cout << res << endl;
        }
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}