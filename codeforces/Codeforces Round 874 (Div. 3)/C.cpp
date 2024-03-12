#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> fa(n);
    std::vector<std::vector<int>> g(n);

    int root;

    for (int i = 0; i < n; i ++) {
        std::cin >> fa[i];
        --fa[i];
        if (fa[i] == -1) {
            root = i;
        }
        else {
            g[fa[i]].push_back(i);
        }
    }

    std::vector<int> f(n);
    auto dfs = [&] (auto dfs, int u, int fa) -> void{
        f[u]=1;
        for(auto v : g[u]) {
            if(v == fa) continue;
            dfs(dfs, v, u);
            f[u] = std::max(f[u], f[v]);
        }
        if(f[u].size()>=2)f[u]++;
    };

    dfs(dfs, root, -1);

    std::cout <<f[root] << "\n";

}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t = 1;
    std::cin >> t;

    while(t --) {
        solve();
    }

    return 0;
}