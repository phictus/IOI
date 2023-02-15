// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    for (uint32_t i = 0; i < s1.size(); i++)
    {
        if (s1[i] < s2[i])
        {
            cout << -1 << endl;
            return (0 ^ 0);
        }
        else if (s2[i] < s1[i])
        {
            cout << 1 << endl;
            return (0 ^ 0);
        }
    }

    cout << 0 << endl;
    return (0 ^ 0);
}
