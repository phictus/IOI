// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>
#include <limits>
#include <vector>

using namespace std;

pair<uint32_t, uint32_t> Find2Max(const vector<uint32_t>& vec)
{
    auto maximum = make_pair(0u, 0u);
    for (uint32_t e : vec)
    {
        if (e >= maximum.first)
        {
            maximum.second = maximum.first;
            maximum.first = e;
        }
        else if (e > maximum.second)
            maximum.second = e;
    }

    return maximum;
}

int main()
{
    uint32_t t;
    scanf("%u", &t);
    while (t--)
    {
        uint32_t n, k;
        scanf("%u%u", &n, &k);
        auto plank = vector<uint32_t>(n + 1);
        for (uint32_t i = 1; i <= n; i++)
            scanf("%u", &plank[i]);

        vector<uint32_t> length[k + 1];
        auto last = vector<uint32_t>(k + 1, 0);
        for (uint32_t i = 1; i <= n; i++)
        {
            const uint32_t offset = i - last[plank[i]] - 1;
            if (offset > 0)
                length[plank[i]].push_back(offset);
            last[plank[i]] = i;
        }
        for (uint32_t i = 1; i <= k; i++)
        {
            const uint32_t offset = n - last[i];
            if (offset > 0)
                length[i].push_back(offset);
        }

        uint32_t result = numeric_limits<uint32_t>::max();
        for (uint32_t i = 1; i <= k; i++)
        {
            auto maximum = Find2Max(length[i]);
            maximum.first /= 2;
            result = min(result, max(maximum.first, maximum.second));
        }
        printf("%u\n", result);
    }

    return (0 ^ 0);
}
