// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        int64_t n;
        cin >> n;
        if (n % 3 == 0)
            cout << "Second\n";
        else
            cout << "First\n";
    }

    return (0 ^ 0);
}
