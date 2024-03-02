// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <map>
#include <cstdint>

using namespace std;

int64_t GetMin(int64_t* a) {
    map<int64_t, int64_t> m;
    for (int64_t i = 0; i < 7; i++) {
        m[a[i]]++;
    }

    for (auto[k, v] : m) {
        if (v == 3) {
            return k;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);

    int64_t x[7], y[7], z[7];
    for (int64_t i = 0; i < 7; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }

    cout << GetMin(x) << ' ';
    cout << GetMin(y) << ' ';
    cout << GetMin(z) << '\n';

    return (0 ^ 0);
}
