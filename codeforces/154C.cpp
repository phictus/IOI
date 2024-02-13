// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <map>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 1000001, mod = 1000000007;
int64_t n, m, power2[maxn], power3[maxn], result = 0;
vector<int64_t> adj[maxn];

int64_t Hash2(const vector<int64_t>& v)
{
    int64_t value = 0;
    for (int64_t e : v)
        value = (value + power2[e]) % mod;

    return value;
}

int64_t Hash3(const vector<int64_t>& v)
{
    int64_t value = 0;
    for (int64_t e : v)
        value = (value + power3[e]) % mod;

    return value;
}

void CountDoubles()
{
    map<Pair, int64_t> m;
    for (int64_t i = 1; i <= n; i++)
        m[make_pair(Hash2(adj[i]), Hash3(adj[i]))]++;

    for (const auto&[k, v] : m)
        result += (v * (v - 1)) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);

    power2[0] = 1;
    power3[0] = 1;
    for (int64_t i = 1; i < maxn; i++)
    {
        power2[i] = (2 * power2[i - 1]) % mod;
        power3[i] = (3 * power3[i - 1]) % mod;
    }

    cin >> n >> m;
    for (int64_t i = 1; i <= m; i++)
    {
        int64_t v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    CountDoubles();
    for (int64_t i = 1; i <= n; i++)
        adj[i].push_back(i);
    CountDoubles();

    cout << result << '\n';

    return (0 ^ 0);
}
