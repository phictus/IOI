// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>
#include <vector>

using namespace std;

uint64_t LIS(uint64_t* array, uint64_t size)
{
    vector<int> result;
    for (int i = 0; i < size; i++)
    {
        auto it = lower_bound(result.begin(), result.end(), array[i]);

        if (it == result.end())
            result.push_back(array[i]);
        else
            *it = array[i];
    }

    return result.size();
}

int main()
{
    uint64_t n;
    scanf("%llu", &n);
    uint64_t array[n];
    for (uint64_t i = 0; i < n; i++)
        scanf("%llu", &array[i]);

    printf("%llu\n", LIS(array, n));

    return (0 ^ 0);
}
