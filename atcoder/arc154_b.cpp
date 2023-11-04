// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <unordered_map>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000;
int64_t n, result, cache;
char a[maxn + 1], b[maxn + 1];

bool Check(int64_t index)
{
    if (cache < 0)
        return false;

    while (a[index] != b[cache])
    {
        cache--;
        if (cache < 0)
            return false;
    }

    cache--;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> a >> b;

    unordered_map<int64_t, int64_t> m;
    for (int64_t i = 0; i < n; i++)
        m[a[i]]++;
    for (int64_t i = 0; i < n; i++)
        m[b[i]]--;

    for (auto[k, v] : m)
    {
        if (v != 0)
        {
            cout << "-1\n";
            return 0;
        }
    }

    result = n;
    cache = n;
    while (result > 0)
    {
        if (!Check(result - 1))
            break;
        result--;
    }

    cout << result << '\n';

    return (0 ^ 0);
}
