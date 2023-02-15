// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int32_t x, y;
    for (uint32_t i = 0; i < 5; i++)
        for (uint32_t j = 0; j < 5; j++)
        {
            uint32_t n;
            cin >> n;
            if (n == 1)
            {
                x = i;
                y = j;
            }
        }
    cout << (int32_t)(abs(2 - x) + abs(2 - y)) << endl;

    return (0 ^ 0);
}
