#include <bits/stdc++.h>
using namespace std;
struct DSU
{
    std::vector<int> f, siz;

    DSU()
    {
    }
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        if(siz[x]<siz[y])swap(x,y);
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
        int operator  [](int x)
    {
        return find(x);
    }
    int size(int x)
    {
        return siz[find(x)];
    }
};
#ifndef ATCODER_DSU_HPP
#define ATCODER_DSU_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

    namespace atcoder
{

    // Implement (union by size) + (path compression)
    // Reference:
    // Zvi Galil and Giuseppe F. Italiano,
    // Data structures and algorithms for disjoint set union problems
    struct dsu
    {
      public:
        dsu() : _n(0)
        {
        }
        explicit dsu(int n) : _n(n), parent_or_size(n, -1)
        {
        }

        int merge(int a, int b)
        {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            int x = leader(a), y = leader(b);
            if (x == y)
                return x;
            if (-parent_or_size[x] < -parent_or_size[y])
                std::swap(x, y);
            parent_or_size[x] += parent_or_size[y];
            parent_or_size[y] = x;
            return x;
        }

        bool same(int a, int b)
        {
            assert(0 <= a && a < _n);
            assert(0 <= b && b < _n);
            return leader(a) == leader(b);
        }

        int leader(int a)
        {
            assert(0 <= a && a < _n);
            if (parent_or_size[a] < 0)
                return a;
            return parent_or_size[a] = leader(parent_or_size[a]);
        }

        int size(int a)
        {
            assert(0 <= a && a < _n);
            return -parent_or_size[leader(a)];
        }

        std::vector<std::vector<int>> groups()
        {
            std::vector<int> leader_buf(_n), group_size(_n);
            for (int i = 0; i < _n; i++)
            {
                leader_buf[i] = leader(i);
                group_size[leader_buf[i]]++;
            }
            std::vector<std::vector<int>> result(_n);
            for (int i = 0; i < _n; i++)
            {
                result[i].reserve(group_size[i]);
            }
            for (int i = 0; i < _n; i++)
            {
                result[leader_buf[i]].push_back(i);
            }
            result.erase(
                std::remove_if(result.begin(), result.end(), [&](const std::vector<int> &v) { return v.empty(); }),
                result.end());
            return result;
        }

      private:
        int _n;
        // root node: -1 * component size
        // otherwise: parent
        std::vector<int> parent_or_size;
    };

} // namespace atcoder

#endif // ATCODER_DSU_HPP
