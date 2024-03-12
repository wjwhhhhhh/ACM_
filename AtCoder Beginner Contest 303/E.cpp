#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
map<int, int> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 N, H;
    cin >> N >> H;
    std::vector<pair<int, int>>va(N);
    vector<i64> ff, w;
    int idx = 0;
    for (int i = 0; i < N; i++)cin >> va[i].first >> va[i].second;
    sort(va.begin(), va.end());
    auto in = [&](int x)
    {
        if (mp.find(x) == mp.end())
        {
            mp[x] = idx++;
            ff.push_back(x), w.push_back(0);
        }

    };
    w.push_back(0);
    auto get = [&](int x)
    {
        return mp[x];
    };
    in(0);
    for(auto i:va)
    {
        in(i.first);
        w[idx-1]=max(w[idx-2],1ll*i.first*i.second);
    }
    for(int i=1;i<idx-1;i++)
    {
        if(H/w[i]<=(ff[i+1]-ff[i]))
        {
            i64 t=(H+w[i]-1)/w[i];
            cout<<ff[i]-1+t;
            return 0;
        }
        H-=(ff[i+1]-ff[i])*w[i];
    }
    i64 t=(H+w[idx-1]-1)/w[idx-1]+ff[idx-1]-1;
    cout<<t<<endl;
    return 0;
}