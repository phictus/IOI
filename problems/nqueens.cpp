// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstring>

using namespace std;

constexpr uint32_t maxn = 25;
bool grid[maxn][maxn];
uint32_t n;

void init()
{
    cin >> n;
    for (uint32_t i = 0; i < n; i++)
        memset(grid[i], 0, n * sizeof(bool));
}

void printGrid()
{
    for (uint32_t i = 0; i < n; i++)
    {
        for (uint32_t j = 0; j < n; j++)
            cout << grid[i][j];
        cout << endl;
    }
}

bool isSafe(uint32_t x, uint32_t y)
{
    int32_t i, j;

    for (i = 0; i < y; i++)
        if (grid[x][i])
            return false;

    for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
        if (grid[i][j])
            return false;

    for (i = x + 1, j = y - 1; j >= 0 && i < n; i++, j--)
        if (grid[i][j])
            return false;

    return true;
}

void solve(uint32_t y)
{
    if (y == n)
    {
        printGrid();
        exit(0);
    }

    for (uint32_t x = 0; x < n; x++)
    {
        if (isSafe(x, y))
        {
            grid[x][y] = true;
            solve(y + 1);
            grid[x][y] = false;
        }
    }
}

int main()
{
    init();
    solve(0);
    cout << "No solution exists." << endl;

    return (0 ^ 0);
}
