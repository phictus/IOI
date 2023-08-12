// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t Abs(int64_t value)
{
    if (value < 0)
        value *= -1;

    return value;
}

constexpr int64_t GetDistance(const Pair& v1, const Pair& v2)
{
    return Abs(v1.first - v2.first) + Abs(v1.second - v2.second);
}

int main()
{
    int64_t n;
    scanf("%lld", &n);

    Pair coords[n + 1];
    for (int64_t i = 1; i <= n; i++)
    {
        int64_t x, y;
        scanf("%lld%lld", &x, &y);
        coords[i] = make_pair(x, y);
    }

    vector<Pair> adjacents[n + 1];
    for (int64_t i = 1; i <= n; i++)
    {
        int64_t c;
        scanf("%lld", &c);
        adjacents[0].push_back(make_pair(c, i));
    }

    int64_t k[n + 1];
    for (int64_t i = 1; i <= n; i++)
    {
        scanf("%lld", &k[i]);
        for (int64_t j = 1; j < i; j++)
        {
            int64_t c = (k[i] + k[j]) * GetDistance(coords[i], coords[j]);
            adjacents[i].push_back(make_pair(c, j));
            adjacents[j].push_back(make_pair(c, i));
        }
    }

    int64_t cost = 0;
    vector<int64_t> stations;
    vector<Pair> connections;

    bool isVisited[n + 1];
    memset(isVisited, 0, (n + 1) * sizeof(bool));

    using QueueType = pair<int64_t, Pair>;
    priority_queue<QueueType, vector<QueueType>, greater<QueueType>> q;
    q.push(make_pair(0, make_pair(0, 0)));

    while (!q.empty())
    {
        QueueType top = q.top();
        q.pop();

        if (isVisited[top.second.first])
            continue;

        isVisited[top.second.first] = true;
        cost += top.first;
        if (top.second.second == 0)
            stations.push_back(top.second.first);
        else
            connections.push_back(make_pair(top.second.first, top.second.second));

        for (const Pair& adj : adjacents[top.second.first])
            if (!isVisited[adj.second])
                q.push(make_pair(adj.first, make_pair(adj.second, top.second.first)));
    }

    printf("%lld\n", cost);

    printf("%lld\n", stations.size() - 1);
    for (auto it = stations.begin() + 1; it != stations.end(); it++)
        printf("%lld\n", *it);

    printf("%lld\n", connections.size());
    for (const Pair& connection : connections)
        printf("%lld %lld\n", connection.first, connection.second);

    return (0 ^ 0);
}
