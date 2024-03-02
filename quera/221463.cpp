// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100;
char a[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false);

    int64_t n, m;
    cin >> n >> m;
    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = 0; j < m; j++) {
            a[i][j] = '.';
        }
    }

    for (int64_t i = 0; i < n; i++) {
        a[i][0] = 'A';
    }
    for (int64_t i = 0; i < m; i++) {
        a[0][i] = 'A';
    }

    for (int64_t i = 0; i < n; i++) {
        a[i][m - 1] = 'B';
    }
    for (int64_t i = 0; i < m; i++) {
        a[n - 1][i] = 'B';
    }

    for (int64_t i = 0; i < n; i++) {
        for (int64_t j = 0; j < m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }

    return (0 ^ 0);
}
