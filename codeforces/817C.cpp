// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>

using namespace std;

int64_t n, s;

int64_t DiffOfNumberAndDigits(int64_t number)
{
    uint64_t result = 0;
    while (number != 0)
    {
        number /= 10;
        result += number;
    }

    return 9 * result;
}


int main()
{
    scanf("%lld%lld", &n, &s);

    int64_t left = 1, right = n;
    while (left <= right)
    {
        const int64_t middle = (right + left) / 2;
        if (DiffOfNumberAndDigits(middle) >= s)
            right = middle - 1;
        else
            left = middle + 1;
    }

    printf("%lld\n", n - right);

    return (0 ^ 0);
}
