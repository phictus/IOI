// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

int64_t Solve()
{
    int64_t n;
    cin >> n;

    int64_t emptyCount = 0, lastEmpty = 0, longestEmpty = 0;
    for (int64_t i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '#')
        {
            longestEmpty = max(longestEmpty, i - lastEmpty);
            lastEmpty = i + 1;
        }
        else
            emptyCount++;
    }
    longestEmpty = max(longestEmpty, n - lastEmpty);

    if (longestEmpty > 2)
        return 2;
    else
        return emptyCount;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
        cout << Solve() << '\n';

    return (0 ^ 0);
}
