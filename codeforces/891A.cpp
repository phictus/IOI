// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>
#include <limits>
#include <algorithm>

using namespace std;

uint64_t GCD(uint64_t a, uint64_t b)
{
    if (a > b)
        swap(a, b);

    if (a == 0)
        return b;

    return GCD(b % a, a);
}

int main()
{
    uint32_t n;
    scanf("%u", &n);

    uint64_t array[n];
    uint32_t numberOfOnes = 0;
    for (uint32_t i = 0; i < n; i++)
    {
        scanf("%llu", &array[i]);
        if (array[i] == 1)
            numberOfOnes++;
    }

    if (numberOfOnes > 0)
    {
        printf("%u\n", n - numberOfOnes);
    }
    else
    {
        uint32_t result = numeric_limits<int32_t>::max();
        for (uint32_t i = 0; i < n; i++)
        {
            uint64_t x = array[i];
            for (uint32_t j = i + 1; j < n; j++)
            {
                x = GCD(x, array[j]);
                if (x == 1)
                {
                    result = min(result, j - i);
                    break;
                }
            }
        }

        if (result == numeric_limits<int32_t>::max())
            printf("-1\n");
        else
            printf("%u\n", result + n - 1);
    }

    return (0 ^ 0);
}
