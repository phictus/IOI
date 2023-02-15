// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    cout << s;
    for (size_t i = s.size(); i > 0; i--)
        cout << s[i - 1];
    cout << endl;

    return (0 ^ 0);
}
