// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

int main()
{
    uint32_t n;
    cin >> n;

    uint32_t ans = 0;
    for (uint32_t i = 0; i < n; i++)
    {
        uint32_t a, b, c;
        cin >> a >> b >> c;
        if (a + b + c > 1)
            ans++;
    }

    cout << ans << endl;

    return (0 ^ 0);
}
