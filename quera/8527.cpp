// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;
constexpr int64_t maxn = 1000000;
int64_t n, height[maxn], dpl[maxn], dpr[maxn];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> height[i];

    dpl[0] = 0;
    for (int64_t i = 1; i < n; i++)
        dpl[i] = max(dpl[i - 1], height[i - 1]);

    dpr[n - 1] = 0;
    for (int64_t i = n - 2; i >= 0; i--)
        dpr[i] = max(dpr[i + 1], height[i + 1]);

    int64_t result = 0;
    for (int64_t i = 0; i < n; i++)
        result += max((int64_t)0, min(dpl[i], dpr[i]) - height[i]);
    cout << result << '\n';

    return (0 ^ 0);
}
