// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <algorithm>
#include <cstdio>
#include <cstdint>

using namespace std;

int main()
{
    uint64_t t;
    scanf("%llu", &t);
    while (t--)
    {
        uint64_t n;
        scanf("%llu", &n);
        uint64_t a[n];
        for (uint64_t i = 0; i < n; i++)
            scanf("%llu", &a[i]);

        sort(a, a + n);
        uint64_t maxElement = a[n - 1];
        uint64_t lengthOfC = 1;
        while (lengthOfC < n && maxElement == a[n - lengthOfC - 1])
        {
            maxElement = a[n - lengthOfC];
            lengthOfC++;
        }

        if (lengthOfC == n)
        {
            printf("-1\n");
            continue;
        }

        printf("%llu %llu\n", n - lengthOfC, lengthOfC);
        for (uint64_t i = 0; i < n; i++)
            printf("%llu\n", a[i]);
    }

    return (0 ^ 0);
}
