// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100000;
int64_t n, a[maxn], cnt1[maxn + 1], cnt2[maxn + 1], mex1, mex2;

void solveTestCase() {
    cin >> n;
    fill(cnt1, cnt1 + n + 1, 0);
    fill(cnt2, cnt2 + n + 1, 0);
    mex1 = 0;
    mex2 = 0;

    for (int64_t i = 0; i < n; i++) {
        cin >> a[i];
        cnt2[a[i]]++;
        while (cnt2[mex2] != 0) {
            mex2++;
        }
    }


    for (int64_t i = 0; i < n - 1; i++) {
        cnt1[a[i]]++;
        cnt2[a[i]]--;
        while (cnt1[mex1] != 0) {
            mex1++;
        }
        if (cnt2[a[i]] == 0 && a[i] < mex2) {
            mex2 = a[i];
        }

        if (mex1 == mex2) {
            cout << "2\n";
            cout << "1 " << i + 1 << '\n';
            cout << i + 2 << ' ' << n << '\n';
            return;
        }
    }

    cout << "-1\n";
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
