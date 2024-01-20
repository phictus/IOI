// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdint>

using namespace std;

bool Check(const string& s, int64_t k)
{
    unordered_map<string, int64_t> m;

    for (int64_t i = 0; i + k <= s.size(); i++)
    {
        if (++m[s.substr(i, k)] >= 2)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int64_t l = 0, r = s.size();
    while (l + 1 != r)
    {
        int64_t mid = (l + r) / 2;
        if (Check(s, mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << '\n';

    return (0 ^ 0);
}
