// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdint>
#include <cstdio>
#include <cstring>

using namespace std;

constexpr uint32_t maxn = 5000001;
uint32_t primeFactor[maxn];
uint32_t numberOfPrimeFactors[maxn];
uint32_t partialSum[maxn];

void Initialize()
{
    memset(primeFactor, 0, maxn * sizeof(uint32_t));
    numberOfPrimeFactors[1] = 0;
    partialSum[1] = numberOfPrimeFactors[1];

    for (uint32_t i = 2; i < maxn; i++)
    {
        if (primeFactor[i] == 0)
            for (uint32_t j = i; j < maxn; j += i)
                primeFactor[j] = i;

        numberOfPrimeFactors[i] = numberOfPrimeFactors[i / primeFactor[i]] + 1;
        partialSum[i] = partialSum[i - 1] + numberOfPrimeFactors[i]; 
    }
}

int main()
{
    Initialize();

    uint32_t t;
    scanf("%u", &t);
    while (t--)
    {
        uint32_t a, b;
        scanf("%u%u", &a, &b);
        printf("%u\n", partialSum[a] - partialSum[b]);
    }

    return (0 ^ 0);
}
