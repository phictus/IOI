// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <unordered_map>
#include <cstdint>

using namespace std;

constexpr int64_t maxa = 1000001;
int64_t n;
unordered_map<int64_t, int64_t> primeCount;

void getPrimeFactors(int64_t x) 
{ 
    while (x % 2 == 0) 
    {
        primeCount[2]++;
        x /= 2;
    }

    for (int64_t i = 3; i * i <= x; i += 2)
    {
        while (x % i == 0)
        {
            primeCount[i]++;
            x /= i;
        }
    }

    if (x > 2)
        primeCount[x]++;
} 

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        primeCount.clear();
        for (int64_t i = 0; i < n; i++)
        {
            int64_t x;
            cin >> x;
            getPrimeFactors(x);
        }

        bool result = true;
        for (auto[k, v] : primeCount)
        {
            if (v % n != 0)
            {
                result = false;
                break;
            }
        }

        if (result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return (0 ^ 0);
}