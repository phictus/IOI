// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <queue>

using namespace std;

struct Vec2
{
    Vec2() :
        x(0), y(0) {}
    explicit Vec2(int32_t x, uint32_t y)
    {
        this->x = x;
        this->y = y;
    }

    int32_t x, y;
};

constexpr uint32_t maxn = 2001;
constexpr uint32_t maxm = 2001;
constexpr uint32_t maxk = 11;
uint32_t n, m, k;
Vec2 start[maxk];

Vec2 ans;
bool visited[maxn][maxm];
const int32_t dx[4] = { 0, 0, -1, 1 };
const int32_t dy[4] = { -1, 1, 0, 0 };
void bfs()
{
    for (uint32_t i = 0; i < n; i++)
        for (uint32_t j = 0; j < m; j++)
            visited[i][j] = false;

    queue<Vec2> q;
    for (uint32_t i = 0; i < k; i++)
    {
        q.push(Vec2(start[i].x - 1, start[i].y - 1));
        visited[start[i].x - 1][start[i].y - 1] = true;
    }

    while (!q.empty())
    {
        ans = q.front();
        q.pop();

        for (uint32_t i = 0; i < 4; i++)
        {
            const int32_t x = ans.x + dx[i];
            const int32_t y = ans.y + dy[i];

            if (!visited[x][y] && x >= 0 && x < n && y >= 0 && y < m)
            {
                q.push(Vec2(x, y));
                visited[x][y] = true;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    for (uint32_t i = 0; i < k; i++)
        cin >> start[i].x >> start[i].y;

    bfs();
    cout << ans.x + 1 << ' ' <<  ans.y + 1 << endl;

    return (0 ^ 0);
}
