#pragma o2;
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <ranges>
#include <set>
#include <string>
#include <vector>

using namespace std;
using i64 = long long;
const int N = 1e3 + 10;
int main()
{

    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<int> ans(1, -1);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    set<int> mp;
    mp.insert(a.back());
    for (auto x : a | std::views::reverse)
    {
        auto it = mp.upper_bound(x);
        if (it == mp.end())
            ans.push_back(-1);
        else
            ans.push_back(*it);
        mp.insert(x);
    }
    std::ranges::reverse(ans);
    // for(int i=N;i>=0;i--)
    // {

    // }
    // reverse(ans.begin(), ans.end());
    for (auto &c : a)
        printf("%d ", c);
}
// 64 位输出请用 printf("%lld")