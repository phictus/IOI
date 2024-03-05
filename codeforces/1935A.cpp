// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

void solveTestCase() {
    int64_t n;
    cin >> n;
    string s;
    cin >> s;

    for (int64_t i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - i - 1]) {
            if (s[i] < s[s.size() - i - 1]) {
                cout << s << '\n';
            } else {
                reverse(s.begin(), s.end());
                cout << s;
                reverse(s.begin(), s.end());
                cout << s << '\n';
            }
            return;
        }
    }

    cout << s << '\n';
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
