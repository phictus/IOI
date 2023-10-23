// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

int64_t GetDist(char src, char dst)
{
    if (src == '0')
        src = '9' + 1;
    if (dst == '0')
        dst = '9' + 1;

    return abs(dst - src);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        char in[4];
        for (int64_t i = 0; i < 4; i++)
            cin >> in[i];

        int64_t result = 0;
        result += GetDist('1', in[0]);
        result += GetDist(in[0], in[1]);
        result += GetDist(in[1], in[2]);
        result += GetDist(in[2], in[3]);
        cout << result + 4 << '\n';
    }

    return (0 ^ 0);
}
