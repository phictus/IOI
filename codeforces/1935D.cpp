// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 300000;
int64_t n, c, s[maxn];
vector<int64_t> v[2];

int64_t get(int64_t i) {
    if (v[s[i] % 2][0] + s[i] > 2 * c) {
        return 0;
    }

    int64_t l = 0, r = v[s[i] % 2].size();
    while (l + 1 < r) {
        int64_t mid = (l + r) / 2;
        if (v[s[i] % 2][mid] + s[i] <= 2 * c) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return r;
}

void solveTestCase() {
    cin >> n >> c;
    int64_t result = ((c + 2) * (c + 1)) / 2;
    for (int64_t i = 0; i < n; i++) {
        cin >> s[i];
        result -= c - s[i] + 1;
        result -= s[i] / 2 + 1;
    }

    for (int64_t i = 0; i < n; i++) {
        v[s[i] % 2].push_back(s[i]);
        result += get(i);
    }
    cout << result << '\n';

    v[0].clear();
    v[1].clear();
}

int main() {
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--) {
        solveTestCase();
    }

    return (0 ^ 0);

}
