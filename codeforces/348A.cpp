// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    uint64_t n;
    cin >> n;
    uint64_t a[n];
    for (uint64_t i = 0; i < n; i++)
        cin >> a[i];

    uint64_t maximum = 0, sum = 0;
    for (uint64_t i = 0; i < n; i++)
    {
        maximum = max(maximum, a[i]);
        sum += a[i];
    }

    uint64_t result = sum % (n - 1) == 0 ?
        max(maximum, sum / (n - 1)) :
        max(maximum, sum / (n - 1) + 1);

    cout << result << endl;

    return (0 ^ 0);
}
