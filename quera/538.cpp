// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <limits>
#include <string>
#include <deque>
#include <cstdint>

using namespace std;

struct Vertex
{
    int64_t x, y;
};

constexpr int64_t maxn = 2000, inf = numeric_limits<int64_t>::max();
int64_t n, m;
Vertex start, finish;
char grid[maxn][maxn];
int64_t dist[maxn + 1][maxn + 1];

int64_t FindMinChange()
{
    constexpr char type[4] = {'\\', '/', '/', '\\'};
    constexpr int64_t dx[4] = {1, 1, -1, -1};
    constexpr int64_t dy[4] = {1, -1, 1, -1};

    deque<Vertex> queue;
    queue.push_front(start);

    for (int64_t x = 0; x <= n; x++)
    {
        for (int64_t y = 0; y <= m; y++)
            dist[x][y] = inf;
    }
    dist[start.x][start.y] = 0;

    while (!queue.empty())
    {
        Vertex v = queue.front();
        queue.pop_front();

        for (int64_t i = 0; i < 4; i++)
        {
            Vertex u = {v.x + dx[i], v.y + dy[i]};
            if (u.x < 0 || u.x > n || u.y < 0 || u.y > m)
                continue;
            int64_t w = type[i] == grid[v.x + (dx[i] - 1) / 2][v.y + (dy[i] - 1) / 2] ? 0 : 1;

            if (dist[u.x][u.y] > dist[v.x][v.y] + w)
            {
                dist[u.x][u.y] = dist[v.x][v.y] + w;
                if (w == 0)
                    queue.push_front(u);
                else
                    queue.push_back(u);
            }
        }
    }

    return dist[finish.x][finish.y];
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    cin >> start.x >> start.y;
    cin >> finish.x >> finish.y;
    for (int64_t x = 0; x < n; x++)
    {
        string s;
        cin >> s;
        for (int64_t y = 0; y < m; y++)
            grid[x][y] = s[y];
    }

    if ((start.x + start.y) % 2 == (finish.x + finish.y) % 2)
        cout << FindMinChange() << '\n';
    else
        cout << "-1\n";

    return (0 ^ 0);
}
