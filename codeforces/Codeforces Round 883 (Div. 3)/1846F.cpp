#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> cnt(10), last(10);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        a[i] = tem;
        cnt[tem]++;
    }
    swap(last, cnt);
    fill(cnt.begin(), cnt.end(), 0);
    cout << "- 0" << endl;
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        a[i] = tem;
        cnt[tem]++;
    }
    bool fl = true;
    for (int i = 0; i < 10; i++)
    {
        if (last[i] != cnt[i])
            fl = false;
    }
    if (fl)
    {
        swap(last, cnt);
        fill(cnt.begin(), cnt.end(), 0);
        cout << "- 0" << endl;
        for (int i = 0; i < n; i++)
        {
            int tem;
            cin >> tem;
            a[i] = tem;
            cnt[tem]++;
        }
    }
    vector<int> need;
    int ing;
    for (int i = 0; i < n; i++)
    {
        if (cnt[a[i]] <= last[a[i]])
            need.push_back(i);
        else
            ing = a[i];
    }
    cout << "- " << need.size() << " ";
    for (int i = 0; i < need.size(); i++)
        cout << need[i] + 1 << " ";
    cout << endl;
    n -= need.size();
    a.resize(n);
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != ing)
            ans = i;
    }
    if (ans != -1)
    {
        cout << "! " << ans + 1 << endl;
        return;
    }
    cout << "- 0" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != ing)
            ans = i;
    }
    cout << "! " << ans + 1 << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}