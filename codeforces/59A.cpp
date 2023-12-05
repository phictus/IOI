// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <cstdint>
#include <cctype>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int64_t count = 0;
    for (char c : s)
    {
        if (isupper(c))
            count++;
    }

    if (2 * count > s.size())
    {
        for (char c : s)
            cout << (char)toupper(c);
        cout << '\n';
    }
    else
    {
        for (char c : s)
            cout << (char)tolower(c);
        cout << '\n';
    }

    return (0 ^ 0);
}
