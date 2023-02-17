// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>

using namespace std;

int main()
{
    uint32_t a, b;
    cin >> a >> b;
    uint32_t ans = 0;
    while (a <= b)
    {
        a *= 3;
        b *= 2;
        ans++;
    }
    cout << ans << endl;

    return (0 ^ 0);
}
