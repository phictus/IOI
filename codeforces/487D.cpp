// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <stack>

using namespace std;

struct Vec2
{
    int32_t x, y;
};

constexpr int32_t maxn = 100000, maxk = 317, maxm = 10;
int32_t n, m, q;
char grid[maxn][maxm];
Vec2 dp[maxn][maxm];

void update(int32_t y0, int32_t y1)
{
    for (int32_t i = y0; i < y1; i++)
    {
        for (int32_t j = 0; j < m; j++)
        {
            if (grid[i][j] == '^')
            {
                if (i % maxk == 0)
                    dp[i][j] = { i - 1, j };
                else
                    dp[i][j] = dp[i - 1][j];
            }
            else if (grid[i][j] == '<')
            {
                if (j == 0)
                    dp[i][j] = { i, j - 1 };
                else
                    dp[i][j] = dp[i][j - 1];
            }
            else
            {
                stack<int32_t> s;
                while (j + 1 < m && grid[i][j + 1] == '>')
                {
                    s.push(j);
                    j++;
                }

                if (j == m - 1)
                    dp[i][j] = { i, j + 1 };
                else if (grid[i][j + 1] == '<')
                    dp[i][j] = { -2, -2 };
                else
                {
                    if (i % maxk == 0)
                        dp[i][j] = { i - 1, j + 1 };
                    else
                        dp[i][j] = dp[i - 1][j + 1];
                }

                while (!s.empty())
                {
                    int32_t x = s.top();
                    s.pop();
                    dp[i][x] = dp[i][x + 1];
                }
            }
        }
    }
}

inline bool check(const Vec2* v)
{
    if (v->x < 0)
        return false;
    if (v->y < 0 || v->y >= m)
        return false;

    return true;
}

void putBread(int32_t x, int32_t y)
{
    const Vec2* result = &dp[x][y];
    while (check(result))
        result = &dp[result->x][result->y];

    cout << result->x + 1 << ' ' << result->y + 1 << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> q;
    for (int32_t i = 0; i < n; i++)
        for (int32_t j = 0; j < m; j++)
            cin >> grid[i][j];

    update(0, n);

    while (q--)
    {
        char option;
        cin >> option;
        if (option == 'A')
        {
            int32_t x, y;
            cin >> x >> y;
            putBread(x - 1, y - 1);
        }
        else
        {
            int32_t x, y;
            char c;
            cin >> x >> y >> c;
            x--;
            y--;

            grid[x][y] = c;
            update((x / maxk) * maxk, min(n, (x / maxk + 1) * maxk));
        }
    }

    return (0 ^ 0);
}
