// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    uint32_t t;
    cin >> t;
    constexpr char codeforces[7] = { 'c', 'o', 'd', 'e', 'f', 'r', 's' };
    while (t--)
    {
        char c;
        cin >> c;
        if (find(codeforces, codeforces + 7, c) != codeforces + 7)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return (0 ^ 0);
}
