// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

int main()
{
    uint32_t n, k;
    cin >> n >> k;
    uint32_t s[n];
    for (size_t i = 0; i < n; i++)
        cin >> s[i];

    uint32_t result = s[n - 1];
    if (n <= k)
        cout << result << endl;
    else
    {
        n -= 2 * k - n;
        for (uint32_t i = 0; i < n / 2; i++)
            result = max(result, s[i] + s[n - i - 1]);

        cout << result << endl;
    }

    return (0 ^ 0);
}
