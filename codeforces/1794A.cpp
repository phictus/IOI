// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str)
{
    const uint32_t n = str.size();
    for (uint32_t i = 0; i < n / 2; i++)
        if (str[i] != str[n - i - 1])
            return false;

    return true;
}

int main()
{
    uint32_t t;
    cin >> t;
    while (t--)
    {
        uint32_t n;
        cin >> n;
        string s1 = "", s2 = "";
        for (uint32_t i = 0; i < 2 * (n - 1); i++)
        {
            string str;
            cin >> str;
            if (str.size() == n - 1)
            {
                if (s1 == "")
                    s1 = str;
                else
                    s2 = str;
            }
        }

        if (isPalindrome(s1 + s2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return (0 ^ 0);
}
