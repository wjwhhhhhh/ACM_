 vector<int> v(ac.tot + 1), in(ac.tot + 1);
    function<bool(int)> dfs = [&](int u) {
        in[u] = v[u] = true;
        for (auto c : edge[u])
        {
            if (in[c])
                return true;
            else if (!v[c] && dfs(c))
                return true;
        }
        in[u] = false;
        return false;
    };