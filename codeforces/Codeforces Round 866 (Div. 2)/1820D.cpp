#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define int __int128
#define fir(i, a, b) for (int i = a; i <= b; i++)
#define dug cout << "ceshi" << endl;
#define met(x, y) memset(x, y, sizeof x)
// #define read(x) scanf("%d",&x)
typedef long long LL;
typedef std::pair<int, int> PII;

void solve()
{
    set<PII> ans;
    int n;
    cin >> n;
    vector<PII> a(n + 1);

    fir(i, 1, n) cin >> a[i].first >> a[i].second;
    int cnt = 0, cnr = 0, sum = 0;
    fir(i, 1, n)
    {
        sum += (a[i].first * a[i].second);
        cnt = max(cnt, a[i].first), cnr = max(cnr, a[i].second);
    }
    if (cnt && sum % cnt == 0)
    {
        ans.insert({cnt, sum / cnt});
    }
    if (cnr && sum % cnr == 0)
    {
        ans.insert(sum / cnr, cnr);
    }
    vector<PII> an;
    for (auto q : ans)
    {
        multiset<PII> xa, xy;
        int h = q.first, w = q.second;
        for (int i = 0; i < n; i++)
        {
            xa.insert({a[i].first, a[i].second}), xy.insert({a[i].second, a[i].first});
        }
        bool fl = false;
        for (int i = 0; i < n; i++)
        {
            auto ita = prev(xa.end());
            if (h == ita->first)
            {
                xy.erase({ita->second, ita->first});
                w -= ita->second;
                xa.erase(ita);
                continue;
            }
            auto itb = prev(xy.end());
            if (h == itb->first)
            {
                xa.erase({itb->second, itb->first});
                w -= itb->second;
                xy.erase(itb);
                continue;
            }
            fl = true;
        }
        if (!fl)
            an.push_back(q);
    }
    cout << an.size() << '\n';
    for (auto i : an)
        cout << i.first << " " << i.second << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // freopen("CON", "r", stdin);
    // system("pause");
    return 0;
}