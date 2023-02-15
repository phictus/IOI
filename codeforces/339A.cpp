// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void add(stringstream& ss, uint32_t value, uint32_t n)
{
    for (uint32_t i = 0; i < n; i++)
        ss << value << '+';
}

int main()
{
    string s;
    cin >> s;
    uint32_t n1 = 0, n2 = 0, n3 = 0;
    for (uint32_t i = 0; i < s.size(); i += 2)
        switch(s[i])
        {
        case '1':
            n1++;
            break;
        case '2':
            n2++;
            break;
        case '3':
            n3++;
            break;
        }
    stringstream ss;
    add(ss, 1, n1);
    add(ss, 2, n2);
    add(ss, 3, n3);
    cout << ss.str().erase(s.size()) << endl;

    return (0 ^ 0);
}
