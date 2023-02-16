// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>

using namespace std;

int main()
{
    uint32_t n;
    cin >> n;
    string s;
    cin >> s;
    uint32_t ans = 0;
    for (uint32_t i = 1; i < n; i++)
        if (s[i - 1] == s[i])
            ans++;
    cout << ans << endl;

    return (0 ^ 0);
}
