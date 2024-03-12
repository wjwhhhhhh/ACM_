#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    set<int> has;
    k -= (n - 1);
    for (int i = n - 2; i; i--)
    {
        if (k >= i)
        {
            has.insert(i);
            k -= i;
        }
    }
    deque<int> ans;
    ans.push_back(n);
    ans.push_front(n - 1);
    int last = 1;
    for (int i = 1; i <= n - 2; i++)
    {
        if (has.find(i) == has.end())
        {
            if (last)
                ans.push_front(n - 1 - i);
            else
                ans.push_back(n - 1 - i);
        }
        else
        {
            if (!last)
                ans.push_front(n - 1 - i);
            else
                ans.push_back(n - 1 - i);
            last = !last;
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}