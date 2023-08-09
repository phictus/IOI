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
        uint64_t sum = 0;
        uint64_t oneCounter = 0;
        for (uint64_t i = 0; i < n; i++)
        {
            uint64_t x;
            cin >> x;
            sum += x;
            if (x == 1)
                oneCounter++;
        }

        if (sum >= oneCounter + n && n > 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return (0 ^ 0);
}
