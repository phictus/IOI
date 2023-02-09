// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>

using namespace std;

int main()
{
    uint32_t n;
    cin >> n;
    for (uint32_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.size() <= 10)
            cout << s << endl;
        else
            cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
    }

    return (0 ^ 0);
}
