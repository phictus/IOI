// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdint>
#include <cstdio>

using namespace std;

constexpr int32_t maxn = 100000;
constexpr int32_t partSize = 350;
int32_t n, q;
int32_t power[maxn];
int32_t lastHole[maxn];
int32_t jumpCount[maxn];

void Update(int32_t i)
{
    if (power[i] >= n || i / partSize != power[i] / partSize)
    {
        lastHole[i] = i;
        jumpCount[i] = 0;
    }
    else
    {
        lastHole[i] = lastHole[power[i]];
        jumpCount[i] = jumpCount[power[i]] + 1;
    }
}

int main()
{
    scanf("%d%d", &n, &q);

    for (int32_t i = 0; i < n; i++)
    {
        scanf("%d", &power[i]);
        power[i] += i;
    }

    for (int32_t i = n - 1; i >= 0; i--)
        Update(i);

    while (q--)
    {
        int32_t option, hole;
        scanf("%d%d", &option, &hole);
        hole--;

        if (option == 0)
        {
            scanf("%d", &power[hole]);
            power[hole] += hole;
            for (int32_t i = hole; i >= 0 && i / partSize == hole / partSize; i--)
                Update(i);
        }
        else
        {
            int32_t resultHole = 0, resultJumpCount = 0;
            while (hole < n)
            {
                resultHole = lastHole[hole];
                resultJumpCount += jumpCount[hole] + 1;
                hole = power[lastHole[hole]];
            }

            printf("%d %d\n", resultHole + 1, resultJumpCount);
        }
    }

    return (0 ^ 0);
}
