// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

int main()
{
    uint32_t n, k;
    cin >> n >> k;

    uint32_t a[n];
    for (uint32_t i = 0; i < n; i++)
        cin >> a[i];

    uint32_t ans = 0;
    for (uint32_t i = 0; i < n; i++)
        if (a[i] >= a[k - 1] && a[i] != 0)
            ans++;
    cout << ans << endl;

    return (0 ^ 0);
}
