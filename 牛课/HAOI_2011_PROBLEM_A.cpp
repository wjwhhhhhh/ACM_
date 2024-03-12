#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 10;
int f[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> r[i] >> l[i];
    int ans = 0;
    vector<int> ll, rr;
    for (int i = 0; i < n; i++)
    {
        if (l[i] + r[i] + 1 > n)
            ans++;
        else
            ll.push_back(l[i] + 1), rr.push_back(n - r[i]);
    }
    vector<int> o(ll.size());
    iota(o.begin(), o.end(), 0);
    sort(o.begin(), o.end(), [&](int x, int y) { return (rr[x] == rr[y] && ll[x] < ll[y]) || rr[x] < rr[y]; });
    vector<int> ord;
    vector<int> len;
    for (int i = 0; i < ll.size(); i++)
    {
        int si = 1;
        ord.push_back(o[i]);
        while (i < ll.size() && ll[o[i]] == ll[o[i + 1]] && rr[o[i]] == rr[o[i + 1]])
        {
            si++, i++;
        }
        len.push_back(si);
    }
    int si = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1];
        while (si < ord.size() && rr[ord[si]] == i)
        {
            f[i] = max(f[i], f[ll[ord[si]] - 1] + min(len[si],rr[ord[si]]-ll[ord[si]]+1));
            si++;
        }
    }
    cout << ans + ll.size() - f[n] << endl;
    return 0;
}