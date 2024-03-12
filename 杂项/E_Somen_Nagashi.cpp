#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    std::set<int> q;
    for (int i = 0; i < n; i++)
    {
        q.insert(i);
    }
    std::set<std::pair<int, int>> S;
    std::vector<i64> ans(n);

    while (m--)
    {
        int t, w, s;
        scanf("%d%d%d", &t, &w, &s);
        while (!S.empty() && S.begin()->first <= t)
        {
            q.insert(S.begin()->second);
            S.erase(S.begin());
        }
        if (!q.empty())
        {
            ans[*q.begin()] += w;
            S.emplace(t + s, *q.begin());
            q.erase(q.begin());
        }
    }

    for (i64 x : ans)
    {
        printf("%lld\n", x);
    }

    return 0;
}