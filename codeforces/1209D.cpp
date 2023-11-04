// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100000;
int64_t n, m, c;
int64_t parent[maxn + 1];

int64_t GetSet(int64_t v)
{
    if (parent[v] == v)
        return v;

    return parent[v] = GetSet(parent[v]);
}

void Union(int64_t v, int64_t u)
{
    if (v != u)
        c--;

    parent[v] = u;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    c = n;
    for (int64_t i = 1; i <= n; i++)
        parent[i] = i;

    for (int64_t i = 1; i <= m; i++)
    {
        int64_t v, u;
        cin >> v >> u;
        Union(GetSet(v), GetSet(u));
    }

    cout << m - n + c << '\n';

    return (0 ^ 0);
}
