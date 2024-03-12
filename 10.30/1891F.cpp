#include <bits/stdc++.h>
using namespace std;
void actualcode();
#define ll long long int
#define ios                                                                                                            \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(NULL);
#define endl "\n"
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
int mod = 1e9 + 7;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("Test_Case_3.txt","r",stdin);
    //     freopen("output8meh.txt","w",stdout);
    // #endif
    actualcode();
}
vector<pair<ll, ll>> v, vi;
int calc(ll x, ll y)
{
    int ans = 0;
    unsigned ll temp = 1;
    while (temp <= x)
    {
        ans++;
        temp *= y;
    }
    return ans - 1;
}
ll powe(ll x, ll y)
{
    ll temp = 1;
    for (int i = 0; i < y; i++)
    {
        temp *= x;
    }
    return temp;
}
void popu()
{
    ll x = 4;
    ll l, r, k = 2;
    ll temp;
    ll f = 1e18;
    f *= 2;
    while (x <= f)
    {
        l = x;
        r = 2 * x - 1;
        if (calc(l, k) == calc(r, k))
        {
            v.push_back({l, calc(l, k)});
            v.push_back({r, calc(r, k)});
        }
        else
        {
            v.push_back({l, calc(l, k)});
            v.push_back({powe(k, calc(l, k) + 1), calc(l, k) + 1});
            v.push_back({r, calc(r, k)});
        }
        k++;
        x *= 2;
    }
}
ll ansf(ll x)
{
    if (x == 3)
        return 0;
    ll prev = 4;
    ll pans = 2;
    ll next = 4;
    ll ans = 0;
    ll temp = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (x < next)
        {
            // cout<<"H\n";
            // cout<<ans<<endl;
            // cout<<prev<<" "<<pans<<" "<<next<<endl;
            temp = x - prev + 1;
            temp *= pans;
            temp %= mod;
            ans += temp;
            ans %= mod;
            // cout<<ans<<endl;
            break;
        }
        else
        {
            temp = next - prev;
            temp *= pans;
            temp %= mod;
            ans += temp;
            ans %= mod;
            prev = v[i].first;
            pans = v[i].second;
            next = v[i + 1].first;
        }
        // cout<<ans<<endl;
        // cout<<prev<<" "<<pans<<" "<<next<<endl;
    }
    return ans;
}
void actualcode()
{
    int t = 1;
    popu();
    vi.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].second != v[i - 1].second)
        {
            vi.push_back(v[i]);
        }
    }
    vi.push_back(v[v.size() - 1]);
    v = vi;
    cin >> t;
    ll zero = 0;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        ll ans = ansf(r)-ansf(l);
        while (ans < 0)
            ans += mod;
        ans %= mod;
        cout << ans << endl;
    }
}