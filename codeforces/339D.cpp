// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 17;
int64_t n, m;
int64_t a[1 << maxn];
int64_t dp[2 * (1 << maxn)];

inline int64_t Process(int64_t type, int64_t a, int64_t b)
{
    return type == 1 ? a | b : a ^ b;
}

void Init(int64_t type = n % 2, int64_t id = 1)
{
    if (id >= (1 << n))
    {
        dp[id] = a[id - (1 << n)];
        return;
    }

    Init(1 - type, 2 * id);
    Init(1 - type, 2 * id + 1);

    dp[id] = Process(type, dp[2 * id], dp[2 * id + 1]);
}

int64_t Query(int64_t index, int64_t type = n % 2, int64_t id = 1, int64_t l = 0, int64_t r = 1 << n)
{
    if (l + 1 == r)
        return dp[id] = a[index];

    int64_t mid = (r + l) / 2;
    if (index < mid)
        return dp[id] = Process(type, Query(index, 1 - type, 2 * id, l, mid), dp[2 * id + 1]);
    else
        return dp[id] = Process(type, Query(index, 1 - type, 2 * id + 1, mid, r), dp[2 * id]);
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int64_t i = 0; i < (1 << n); i++)
        cin >> a[i];

    Init();

    while (m--)
    {
        int64_t index;
        cin >> index;
        index--;

        cin >> a[index];
        cout << Query(index) << '\n';
    }

    return (0 ^ 0);
}
