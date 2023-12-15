// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

string s;
int64_t cnt[2019];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s;
    int64_t x = 0, y = 1;
    cnt[0]++;
    for (int64_t i = s.size() - 1; i >= 0; i--)
    {
        x = (x + y * (int64_t)(s[i] - '0')) % 2019;
        y = (y * 10) % 2019;
        cnt[x]++;
    }

    int64_t result = 0;
    for (int64_t i = 0; i < 2019; i++)
        result += (cnt[i] * (cnt[i] - 1)) / 2;
    cout << result << '\n';

    return (0 ^ 0);
}
