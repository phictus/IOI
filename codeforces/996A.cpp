// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t n;
    cin >> n;

    int64_t result = 0;
    const int64_t bill[] = {1, 5, 10, 20, 100};

    for (int64_t i = 4; i >= 0; i--)
    {
        result += n / bill[i];
        n %= bill[i];
    }

    cout << result << '\n';

    return (0 ^ 0);
}
