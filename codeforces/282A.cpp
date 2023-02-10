// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>

using namespace std;

int main()
{
    uint32_t n;
    cin >> n;

    int32_t plus = 0, minus = 0;
    for (uint32_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s[1] == '+')
            plus++;
        else
            minus++;
    }

    cout << plus - minus << endl;

    return (0 ^ 0);
}
