// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

constexpr uint64_t mod = 998244353;

uint64_t modPower(uint64_t a, uint64_t b)
{
    if (b == 0)
        return 1;

    uint64_t result = modPower(a, b / 2);
    if (b % 2 == 0)
        result *= result;
    else
        result *= (result * a) % mod;

    return result % mod;
}

int main()
{
    uint64_t n;
    cin >> n;

    /**
     * E[n] = E[n - 1] + 1 + (1 - p[n])(E[n])
     * ==> E[n] = (E[n - 1] + 1) / p[n]
    **/
    uint64_t e = 0;
    for (uint64_t i = 0; i < n; i++)
    {
        uint64_t p;
        cin >> p;
        const uint64_t pInverse = modPower(p, mod - 2); // Fermat's little theorem
        e = (e + 1) * 100 % mod;
        e = e * pInverse % mod;
    }

    cout << e << endl;

    return (0 ^ 0);
}
