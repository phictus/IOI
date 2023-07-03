// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdlib>
#include <cstdint>

using namespace std;

char grid[8][8];

void Backtrack(uint32_t t, int32_t x, int32_t y)
{
    if (y + t < 8 && grid[x][y + t] == 'S')
        return;

    bool winCondition = true;
    for (uint32_t i = y + 1; i + t < 8; i++)
    {
        if (grid[x][i + t] == 'S')
            winCondition = false;
    }

    if (winCondition)
    {
        printf("WIN\n");
        exit(0);
    }

    constexpr int32_t xOffset[] = {0, 1, -1, 1, -1, 1, -1, 0, 0};
    constexpr int32_t yOffset[] = {0, 1, -1, -1, 1, 0, 0, 1, -1};

    for (uint32_t i = 0; i < 9; i++)
    {
        const int32_t newX = x + xOffset[i];
        const int32_t newY = y + yOffset[i];

        if (newX >= 0 && newX < 8 &&
            newY >= 0 && newY < 8 &&
            grid[newX][newY + t] != 'S')
            Backtrack(t + 1, newX, newY);
    }
}

int main()
{
    for (int32_t i = 7; i >= 0; i--)
    {
        for (uint32_t j = 0; j < 8; j++)
        {
            do scanf("%c", &grid[j][i]);
            while (grid[j][i] == '\n');
        }
    }

    Backtrack(0, 0, 0);
    printf("LOSE\n");

    return (0 ^ 0);
}
