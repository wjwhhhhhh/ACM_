#include <bits/stdc++.h>
#define dug(x) cerr << "死了吧小丑" << x << endl
#define fir(a, b, c) for (int a = b; a < c; a++)
using namespace std;
using i64 = long long;
using two = array<i64, 2>;
template <class T> bool chmax(T &a, T b)
{
    a > b ? (a = a) : (a = b);
    return a == b;
}
template <class T> bool chmin(T &a, T b)
{
    a > b ? (a = b) : (a = a);
    return a == b;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int n;
    cin >> n;
    vector<two> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1];
    vector<i64> all;
    fir(i, 0, n) all.push_back(a[i][0]), all.push_back(a[i][0] + a[i][1]);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    int idx = 0;
    map<i64, int> mp;
    for (auto c : all)
    {
        mp[c] = idx++;
    }
    vector<vector<i64>> cnt(idx);
    fir(i, 0, n)
    {
        cnt[mp[a[i][0]]].push_back(a[i][0] + a[i][1]);
    }
    i64 ing = 0, ans = 0;
    priority_queue<i64, vector<i64>, greater<i64>> st;
    for (int i = 0; i < idx; i++)
    {
        if (cnt[i].size() == 0)
            continue;
        while (st.size() && ing < all[i])
        {
            while (st.size() && st.top() < ing)
            {
                st.pop();
            }
            if (st.size() == 0)
                break;
            st.pop();
            ing++, ans++;
        }
        if (st.size() == 0)
            ing = all[i];
        for (auto c : cnt[i])
            st.push(c);
    }
    while (st.size())
    {
        while (st.size() && st.top() < ing)
        {
            st.pop();
        }
        if (st.size() == 0)
            break;
        st.pop();
        ing++, ans++;
    }
    cout << ans << endl;
    return 0;
}