#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<int> T(m);
    vector<vector<int>> cnt(m);
    unordered_map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < m; i++)
    {
        int len;
        cin >> len >> T[i];
        cnt[i].resize(len);
        for (int j = 0; j < len; j++)
        {
            cin >> cnt[i][j];
            cnt[i][j]--;
            mp[cnt[i][j]].push_back({i, j});
        }
    }
    vector<int> dist(n, -1), v(n);
    dist[s] = 0;
    priority_queue<pair<int, int>> st;
    st.push({0, s});
    while (st.size())
    {
        auto x = st.top().second;
        st.pop();
        if (v[x])
            continue;
        v[x] = true;
        for (int i = 0; i < mp[x].size(); i++)
        {
            auto [a, b] = mp[x][i];
            int t;
            if(dist[x]<=b)t=b;
            else  t = (dist[x] - b + T[a] - 1) / T[a] * T[a] + b;
            if (b + 1 != cnt[a].size())
            {
                int y = cnt[a][b + 1];
                if (dist[y] == -1 ||  t + 1 < dist[y])
                {
                    //cout<<y<<endl;
                    dist[y] =  t + 1;
                    st.push({-dist[y], y});
                }
            }
        }
    }
    for (auto i : dist)
        cout << i <<'\n';
    return 0;
}