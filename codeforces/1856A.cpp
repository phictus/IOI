// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    uint64_t t;
    cin >> t;
    while (t--)
    {
        uint64_t n;
        cin >> n;
        uint64_t a[n];
        for (uint64_t i = 0; i < n; i++)
            cin >> a[i];

        uint64_t r = n - 1;
        while (r != 0 && a[r] >= a[r - 1])
            r--;

        uint64_t result = 0;
        for (uint64_t i = 0; i < r; i++)
            result = max(result, a[i]);

        cout << result << endl;
    }

    return (0 ^ 0);
}
