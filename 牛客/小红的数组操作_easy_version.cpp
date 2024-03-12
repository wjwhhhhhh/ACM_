#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p, x, q, y;
    cin >> n >> x >> p >> y >> q;
    i64 sum = 0;
    for (int i = 0; i < n; i++)
    {
        int tem;
        cin >> tem;
        sum += tem;
        sum %= n;
    }
    q = (n - q % n) % n;
    p = p % n;
    vector<int> has;
    map<int, int> st;
    has.push_back(0);
    st[0] = 0;
    int idx = 1;
    int ing = q;
    while (st.find(ing) == st.end())
    {
        has.push_back(ing);
        st[ing] = idx++;
        ing = (ing + q) % n;
    }
    i64 ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        i64 need = (n - (sum + 1ll * i * p) % n + n) % n;
        if (st.find(need) != st.end())
        {
            // cout << i << need << endl;
            ans = min(ans, 1ll * i * x + st[need] * y);
        }
    }
    cout << ans << endl;
    return 0;
}