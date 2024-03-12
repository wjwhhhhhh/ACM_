#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> rank(n);
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string tem;
        cin >> tem;
        rank[i] = i;
        mp[tem] = i;
    }
    int m;
    cin >> m;
    cout << m << '\n';
    int idx = -1;
    for (int i = 0; i < m; i++)
    {
        string tem;
        cin >> tem;
        int id = mp[tem];
        int si = 1;
        for (int j = 0; j < n; j++)
        {
            if (rank[j] < rank[id])
                si++;
        }
        rank[id] = idx--;
        cout << si << '\n';
    }
    return 0;
}