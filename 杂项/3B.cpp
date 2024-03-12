#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
using namespace std;
using i64 = long long;
template <class T> void chkmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
}
template <class T> void chkmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n, v;
    cin >> n >> v;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    vector<pair<int, int>> st[2];
    for (int i = 0; i < n; i++)
    {
        st[a[i] - 1].push_back({b[i], i});
    }
    sort(st[0].begin(), st[0].end()), sort(st[1].begin(), st[1].end());
    i64 ans = 0;
    vector<int> cnt;
    while (v)
    {
        if (st[0].size() == 0 && st[1].size() == 0)
        {
            break;
        }
        if (v == 1)
        {
            if (st[0].size())
            {
                ans += st[0].back().first;
                cnt.push_back(st[0].back().second);
                st[0].pop_back();
                v--;
            }
            else
                break;
        }
        else
        {
            if (st[1].size() == 0)
            {
                ans += st[0].back().first;
                cnt.push_back(st[0].back().second);
                st[0].pop_back();
                v--;
            }
            else if (st[0].size() == 0)
            {
                ans += st[1].back().first;
                cnt.push_back(st[1].back().second);
                st[1].pop_back();
                v -= 2;
            }
            else if (st[0].size() == 1)
            {
                if (st[1].back().first > st[0].back().first)
                {
                    ans += st[1].back().first;
                    cnt.push_back(st[1].back().second);
                    st[1].pop_back();
                    v -= 2;
                }
                else
                {
                    ans += st[0].back().first;
                    cnt.push_back(st[0].back().second);
                    st[0].pop_back();
                    v--;
                }
            }
            else
            {
                int siz = st[0].size();
                if (st[1].back().first >= st[0][siz - 1].first + st[0][siz - 2].first)
                {
                    ans += st[1].back().first;
                    cnt.push_back(st[1].back().second);
                    st[1].pop_back();
                    v -= 2;
                }
                else
                {
                    ans += st[0].back().first;
                    cnt.push_back(st[0].back().second);
                    st[0].pop_back();
                    v--;
                }
            }
        }
    }
    // sort(cnt.begin(), cnt.end());
    cout << ans << endl;
    for (auto ch : cnt)
    {
        cout << ch + 1 << " ";
    }
    return 0;
}