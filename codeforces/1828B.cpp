// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
    if (a > b)
        swap(a, b);

    if (a == 0)
        return b;
    else
        return gcd(a, b % a);
}

int main()
{
    int64_t t;
    cin >> t;
    while (t--)
    {
        int64_t n;
        cin >> n;
        int64_t p[n];
        for (int64_t i = 0; i < n; i++)
            cin >> p[i];

        int64_t result = 0;
        for (int64_t i = 1; i <= n; i++)
            result = gcd(result, abs(i - p[i - 1]));
        cout << result << endl;
    }

    return (0 ^ 0);
}
