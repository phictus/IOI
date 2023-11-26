// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int64_t n;
string a;

int64_t Solve()
{
    cin >> n >> a;

    int64_t result = 0, count = 0;
    for (int64_t i = 0; i < n; i++)
    {
        if (a[i] == 'A')
            count++;
        else
        {
            result += count;
            count = min(count, (int64_t)1);
        }
    }

    return result;
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
