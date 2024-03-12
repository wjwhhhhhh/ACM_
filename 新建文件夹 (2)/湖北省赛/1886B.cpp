
#include <bits/stdc++.h>

using i64 = long long;
using namespace std;
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
int main()
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    // cout<<1<<endl;
    int N = 5, M = 2, W = 6, WW = 20;
    cout << N << " ";
    vector<int> a(N);
    iota(a.begin(), a.end(), 1);
    shuffle(a.begin(), a.end(), rnd);
    set<int> has;
    for (int i = 1; i <= M; i++)
    {
        has.insert(rnd() % N + 1);
    }
    cout << has.size() << endl;
    for (int i = 1; i < N; i++)
    {
        cout << a[i] << " " << a[i - 1] << endl;
    }
    // cout<<endl;
    // for(int i=0;i<M ;i++)
    // {
    //     cout<<rnd()%WW+1<<' ';
    // }
    return 0;
}
