// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    constexpr char vowels[6] = { 'a', 'e', 'o', 'u', 'i', 'y' };
    stringstream ss;
    for (char e : s)
        if (find(vowels, vowels + 6, e) == vowels + 6)
            ss << '.' << e;

    cout << ss.str() << endl;

    return (0 ^ 0);
}
