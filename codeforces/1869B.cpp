// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>

using namespace std;

struct Vec2
{
    int64_t x, y;
};

constexpr int64_t maxn = 200001;
int64_t n, k, src, dst;
Vec2 pos[maxn];

inline int64_t getDist(int64_t v, int64_t u)
{
    return abs(pos[v].x - pos[u].x) + abs(pos[v].y - pos[u].y);
}

int64_t getClosestMajor(int64_t v)
{
    int64_t result = numeric_limits<int64_t>::max() / 2;
    for (int64_t i = 1; i <= k; i++)
        result = min(result, getDist(v, i));

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t q;
    cin >> q;
    while (q--)
    {
        cin >> n >> k >> src >> dst;
        for (int64_t i = 1; i <= n; i++)
            cin >> pos[i].x >> pos[i].y;

        cout << min(getClosestMajor(src) + getClosestMajor(dst), getDist(src, dst)) << '\n';
    }

    return (0 ^ 0);
}
