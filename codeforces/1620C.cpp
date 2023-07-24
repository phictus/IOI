// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

void Compute(uint64_t n, uint64_t m, uint64_t k, const string& str, vector<uint64_t>& result)
{
    vector<uint64_t> components;
    uint64_t asterisksCounter = 0;

    for (uint64_t e : str)
    {
        if (e == '*')
            asterisksCounter++;
        else
        {
            components.push_back(asterisksCounter * m + 1);
            asterisksCounter = 0;
        }
    }

    for (auto it = components.rbegin(); it != components.rend(); it++)
    {
        result.push_back(k % *it);
        k /= *it;
    }
}

void Print(const vector<uint64_t>& result)
{
    stringstream stream;
    for (auto it = result.rbegin(); it != result.rend(); it++)
    {
        for (uint64_t i = 0; i < *it; i++)
            stream << 'b';
        stream << 'a';
    }

    string str = stream.str();
    cout << str.substr(0, str.size() - 1) << endl;

}

int main()
{
    uint64_t t;
    cin >> t;
    while (t--)
    {
        uint64_t n, m, k;
        string str;

        cin >> n >> m >> k;
        cin >> str;

        k--;
        str += 'a';

        vector<uint64_t> result;
        Compute(n, m, k, str, result);
        Print(result);
    }

    return (0 ^ 0);
}
