// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    uint32_t q;
    cin >> q;
    while (q--)
    {
        uint32_t n, notEqual = 0, zeros = 0, ones = 0;
        cin >> n;
        char s[n];
        for (uint32_t i = 0; i < n; i++)
            cin >> s[i];

        char result[n + 2];
        for (uint32_t i = 0; i <= n; i++)
            result[i] = '0';
        result[n + 1] = '\0';

        uint32_t l = 0, r = n - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                notEqual++;
            else
            {
                if (s[l] == '0')
                    zeros++;
                if (s[l] == '1')
                    ones++;
            }

            l++;
            r--;
        }

        if (notEqual == 0)
            result[0] = '1';
        uint32_t odd = n % 2;

        for (uint32_t i = 1; i <= n; i++)
        {
            if (notEqual > i)
                continue;
            if (i - notEqual > 2 * (ones + zeros) + odd)
                continue;

            if ((i - notEqual) % 2 == 1)
            {
                if (odd == 0)
                    continue;
                else
                    result[i] = '1';
            }
            else
                result[i] = '1';
        }

        cout << result << '\n';
    }

    return (0 ^ 0);
}
