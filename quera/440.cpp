// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 450, maxk = 100001, mod = 1000000007;
int64_t n, k, dp[2][maxk];
struct Edge {
    int64_t v, u, l, r, c;
} e[maxn];
vector<int64_t> adj[maxn];

void init(int64_t v = 1, int64_t p = 0, int64_t lastEdge = 0) {
    for (int64_t i : adj[v]) {
        int64_t u = e[i].v + e[i].u - v;
        if (u == p) {
            continue;
        }

        init(u, v, i);
        e[lastEdge].c += e[i].c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int64_t i = 1; i < n; i++) {
        int64_t v, u, l, r;
        cin >> v >> u >> l >> r;
        if (n < maxn) {
            e[i] = {v, u, l, r, 1};
            adj[v].push_back(i);
            adj[u].push_back(i);
        }
    }
    if (n >= maxn) {
        cout << "0\n";
        return (0 ^ 0);
    }

    init();
    dp[0][0] = 1;
    for (int64_t i = 1; i < n; i++) {
        int64_t r = i % 2, m = e[i].c * (n - e[i].c);

        for (int64_t j = 0; j < m * e[i].l; j++) {
            dp[r][j] = 0;
        }
        for (int64_t j = m * e[i].l; j <= k; j++) {
            dp[r][j] = dp[1 - r][j - m * e[i].l] + dp[r][j - m] % mod;
            if (j >= m * (e[i].r + 1)) {
                dp[r][j] = (dp[r][j] - dp[1 - r][j - m * (e[i].r + 1)] + mod) % mod;
            }
        }
    }

    int64_t result = 0;
    for (int64_t i = 0; i <= k; i++) {
        result += dp[(n - 1) % 2][i];
        result %= mod;
    }
    cout << result << '\n';

    return (0 ^ 0);
}
