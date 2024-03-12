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
struct SAM
{
    const int MAXM = 1e6 + 5;
    struct State
    {
        int fa, len, next[26];
    } sam[MAXM];
    int cnt = 1, last = 1;
    void insert(int ch)
    { // 插入时要-'a'（或其他）
        int cur = ++cnt, p;
        sam[cur].len = sam[last].len + 1;
        for (p = last; p && !sam[p].next[ch]; p = sam[p].fa)
            sam[p].next[ch] = cur;
        int q = sam[p].next[ch];
        if (q == 0)
        {
            sam[cur].fa = 1;
        }
        else if (sam[p].len + 1 == sam[q].len)
        {
            sam[cur].fa = q;
        }
        else
        {
            int r = ++cnt;
            sam[r] = sam[q];
            sam[r].len = sam[p].len + 1;
            for (; p && sam[p].next[ch] == q; p = sam[p].fa)
                sam[p].next[ch] = r;
            sam[cur].fa = sam[q].fa = r;
        }
        last = cur;
    }
}; // namespace SAM
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n = 10;
    std::string s;
    s.resize(n);
    cout << s << "hj" << endl;
    // freopen("test.txt", "r", stdin);

    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}