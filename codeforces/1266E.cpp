#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int g[N][N];
set<int> man, woman;
vector<int> ansman, answoman;
int dist[N];
bool v[N];
int n;
int maxman = 0x3f3f3f3f, maxwoman = 0x3f3f3f3f;
void dija(int s)
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<int, int>> st;
    memset(v, 0, sizeof v);
    dist[s] = 0;
    st.push({0, s});
    while (st.size())
    {

        int who = st.top().second;
        st.pop();
        if (v[who])
            continue;
        v[who] = true;

        for (int i = 1; i <= n; i++)
        {
            if (g[i][who] + dist[who] < dist[i])
            {
                dist[i] = g[i][who] + dist[who];
                st.push({-dist[i], i});
            }
        }
    }
}
int main()
{

    cin >> n;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++)
    {
        string flag;
        cin >> flag;
        if (flag == "F")
            woman.insert(i);
        else
            man.insert(i);

        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int a, b;
            scanf("%d:%d", &a, &b);
            g[a][i] = b;
        }
    }
    for (int i = 1; i <= 1; i++)
    {
        dija(i);
        int tem = 0;
        for (int i = 1; i <= n; i++)
            cout << dist[i] << " ";
        if (man.find(i) != man.end())
        {
            for (auto j : woman)
            {
                tem = max(tem, dist[j]);
            }

            if (tem == maxman)
                ansman.push_back(i);
            else if (tem < maxman)
            {
                maxman = tem;
                ansman.clear(), ansman.push_back(i);
            }
        }
        else
        {
            for (auto j : man)
            {
                // if (i == 3)
                //     cout << dist[j] << " ";
                tem = max(tem, dist[j]);
            }
            if (tem == maxwoman)
                answoman.push_back(i);
            else if (tem < maxwoman)
            {
                maxwoman = tem;
                answoman.clear(), answoman.push_back(i);
            }
        }
        // cout << tem << endl;
    }
    // for (auto i : answoman)
    //     cout << i << ' ';
    // puts("");
    // for (auto i : ansman)
    //     cout << i << " ";
}