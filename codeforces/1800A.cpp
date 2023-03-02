// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string removeDuplicates(const string& str)
{
    stringstream stream;
    char lastC = ' ';
    for (char c : str)
    {
        if (c != lastC)
        {
            stream << c;
            lastC = c;
        }
    }

    return stream.str();
}

int main()
{
    uint32_t t;
    cin >> t;
    while (t--)
    {
        uint32_t n;
        cin >> n;
        string str;
        cin >> str;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        if (removeDuplicates(str) == "meow")
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return (0 ^ 0);
}
