#pragma GCC optimize(3,"Ofast","inline")

#include <bits/stdc++.h>

using i64 = long long;
using namespace std;

template<typename T> std::istream& operator>>(std::istream& is, std::vector<T>& v) { for (auto& i : v) is >> i; return is; }
template<typename T> std::ostream& operator<<(std::ostream& os, std::vector<T>& v) { for (int i = 0; i < v.size(); i++) os << v[i] << " "[i != v.size() - 1]; return os; }
int n=3,m=4;
std::vector a(n, std::vector<int>(m));

bool slove()
{


    int ans = 0;
    auto check = [&](int x1, int x2, int y1, int y2) {
        int cnt[2]{};
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
            if(a[i][j]!=a[x1][y1])return false;
            }
        }
        return true;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int u = i; u < n; u++) {
                for (int v = j; v < m; v++) {
                    ans += check(i, u, j, v);
                }
            }
        }
    }

    return (2*ans)==(n * (n + 1) * m * (m + 1) / 4 );
}
void dfs(int x)
{
    if(x==n*m)
    {
        if(slove())
        {
            for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            cout<<a[i][j]<<' ';
                }
                cout<<endl;
            }
            cout<<endl;
        }
        return ;
    }
    a[x/m][x%m]=0;
    dfs(x+1);
    a[x/m][x%m]=1;
    dfs(x+1);
}
int32_t main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    dfs(0);

    return 0;
}