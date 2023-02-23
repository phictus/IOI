// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>
#include <stack>

using namespace std;

enum class Type : uint8_t
{
    Opening,
    Closing
};

Type getType(char c)
{
    constexpr char characters[4] = { '{', '[', '(', '<' };
    for (uint32_t i = 0; i < 4; i++)
        if (c == characters[i])
            return Type::Opening;
    return Type::Closing;
}

char getOpening(char c)
{
    switch (c)
    {
    case '}': return '{';
    case ']': return '[';
    case ')': return '(';
    default: return '<';
    }
}

int main()
{
    string str;
    cin >> str;

    int32_t count = 0;
    for (char e : str)
    {
        if (getType(e) == Type::Opening)
            count++;
        else
            count--;

        if (count < 0)
        {
            cout << "Impossible" << endl;
            return (0 ^ 0);
        }
    }
    if (count > 0)
    {
        cout << "Impossible" << endl;
        return (0 ^ 0);
    }

    stack<char> s;
    uint32_t ans = 0;
    for (char e : str)
    {
        if (getType(e) == Type::Opening)
            s.push(e);
        else
        {
            if (getOpening(e) != s.top())
                ans++;
            s.pop();
        }
    }

    cout << ans << endl;

    return (0 ^ 0);
}
