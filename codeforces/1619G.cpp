// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
using Pair = pair<int64_t, int64_t>;
using PLMap = map<Pair, int64_t>;
using LVHashMap = unordered_map<int64_t, vector<int64_t>>;

constexpr int64_t maxn = 200000;
int64_t n, k;
int64_t parent[maxn];

int64_t FindSet(int64_t v)
{
    if (parent[v] == v)
        return v;

    parent[v] = FindSet(parent[v]);
    return parent[v];
}

int main()
{
    int64_t q;
    scanf("%lld", &q);

    while (q--)
    {
        scanf("%lld%lld", &n, &k);
        for (int64_t i = 0; i < n; i++)
            parent[i] = i;

        PLMap id;
        int64_t time[n];
        LVHashMap minesAtX;
        LVHashMap minesAtY;
        for (int64_t i = 0; i < n; i++)
        {
            int64_t x, y, t;
            scanf("%lld%lld%lld", &x, &y, &t);

            id[make_pair(x, y)] = i;
            time[i] = t;
            minesAtX[x].push_back(y);
            minesAtY[y].push_back(x);
        }

        for (auto& mines : minesAtX)
        {
            sort(mines.second.begin(), mines.second.end());

            for (int64_t i = 1; i < mines.second.size(); i++)
            {
                if (mines.second[i] - mines.second[i - 1] <= k)
                {
                    const int64_t mine1 = id[make_pair(mines.first, mines.second[i - 1])];
                    const int64_t mine2 = id[make_pair(mines.first, mines.second[i])];

                    time[FindSet(mine1)] = min(time[FindSet(mine1)], time[FindSet(mine2)]);
                    parent[FindSet(mine2)] = FindSet(mine1);
                }
            }
        }

        for (auto& mines : minesAtY)
        {
            sort(mines.second.begin(), mines.second.end());

            for (int64_t i = 1; i < mines.second.size(); i++)
            {
                if (mines.second[i] - mines.second[i - 1] <= k)
                {
                    const int64_t mine1 = id[make_pair(mines.second[i - 1], mines.first)];
                    const int64_t mine2 = id[make_pair(mines.second[i], mines.first)];

                    time[FindSet(mine1)] = min(time[FindSet(mine1)], time[FindSet(mine2)]);
                    parent[FindSet(mine2)] = FindSet(mine1);
                }
            }
        }

        vector<int64_t> results;
        bool isUsed[n];
        fill(isUsed, isUsed + n, false);
        for (int64_t i = 0; i < n; i++)
        {
            if (isUsed[FindSet(i)])
                continue;
            isUsed[FindSet(i)] = true;
            results.push_back(time[FindSet(i)]);
        }

        const int64_t size = (int64_t)results.size();
        int64_t result = size - 1;
        sort(results.begin(), results.end());
        for (int i = 0; i < size; i++)
            result = min(result, max(size - i - 2, results[i]));

        printf("%lld\n", result);
    }

    return (0 ^ 0);
}
