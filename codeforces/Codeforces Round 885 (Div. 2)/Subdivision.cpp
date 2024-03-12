
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0)
#define LL long long
#define maxn (int)(1e6 + 10)

int n, m;
LL w[550], u[550], v[550];
int p[550], r[550];
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
pair<LL, int> Kruskal(LL xx)
{
    LL ans = 0;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
        r[i] = i;
    sort(r + 1, r + m + 1, [xx](const int i, const int j) {
        LL wa = abs(w[i] - xx);
        LL wb = abs(w[j] - xx);
        if (wa != wb)
            return wa < wb;
        return w[i] > w[j]; // 由于x往右偏移的时候对右边的值更友好，所以相等时右边的值理应更优先
    });
    int cc = 0;
    for (int i = 1; i <= m; i++)
    {
        int e = r[i];
        int x = find(u[e]);
        int y = find(v[e]);
        if (x != y)
        {
            ans += abs(w[e] - xx);
            p[x] = y;
            cc += xx < w[e];
        }
    }
    return {ans, cc};
}

vector<LL> res;
vector<int> cnt;

LL P, k, a, b, c;
int main()
{
    IOS;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        w[i] *= 2;
    }

    vector<LL> ev(1, 0);
    for (int i = 1; i <= m; i++)
        for (int j = i; j <= m; j++)
            ev.push_back(w[i] + w[j] >> 1);
    sort(ev.begin(), ev.end());
    ev.resize(unique(ev.begin(), ev.end()) - ev.begin());

    for (auto xx : ev)
    {
        auto ss = Kruskal(xx);
        cout << ss.first << endl;
        res.push_back(ss.first);
        cnt.push_back(ss.second);
    }

    LL ans = 0;
    cin >> P >> k >> a >> b >> c;
    LL x;
    for (LL cas = 1; cas <= k; cas++)
    {
        if (cas <= P)
            cin >> x;
        else
            x = (x * a + b) % c;

        int pos = upper_bound(ev.begin(), ev.end(), 2 * x) - ev.begin() - 1;
        ans ^= (res[pos] + (n - 1 - 2 * cnt[pos]) * 1ll * (2 * x - ev[pos])) / 2;
        // 加上左右两边点的个数的差值
    }
    cout << ans << endl;
}
