// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>

using namespace std;

int main()
{
    uint32_t t;
    cin >> t;
    while (t--)
    {
        uint32_t n;
        cin >> n;
        string s;
        cin >> s;

        uint32_t m = 0;
        for (uint32_t i = 0; 2 * i < n; i++)
        {
            if (s[i] == s[n - i - 1])
                break;
            m++;
        }

        cout << n - (m * 2) << endl;
    }

    return (0 ^ 0);
}
