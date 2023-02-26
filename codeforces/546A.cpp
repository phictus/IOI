// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

int main()
{
    int32_t k, n, w;
    cin >> k >> n >> w;
    int32_t ans = (k * w * (w + 1)) / 2 - n;
    if (ans < 0)
        cout << 0 << endl;
    else
        cout << ans << endl;

    return (0 ^ 0);
}
