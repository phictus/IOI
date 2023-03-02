// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<uint64_t>::iterator findMaximum(vector<uint64_t>& v, uint32_t l, uint32_t r)
{
    uint64_t maximum = 0;
    vector<uint64_t>::iterator result;
    for (auto iter = v.begin() + l; iter != v.begin() + r; iter++)
        if (*iter >= maximum)
        {
            result = iter;
            maximum = *iter;
        }

    return result;
}

int main()
{
    uint32_t t;
    cin >> t;
    while (t--)
    {
        uint32_t n;
        cin >> n;
        uint64_t s[n];
        for (uint32_t i = 0; i < n; i++)
            cin >> s[i];

        uint64_t ans = 0;
        uint32_t offset = 0;
        vector<uint64_t> v;
        for (uint32_t i = 0; i < n; i++)
        {
            if (s[i] != 0)
                v.push_back(s[i]);
            else
            {
                if (v.size() > 0)
                {
                    auto iter = findMaximum(v, 0, i - offset);
                    ans += *iter;
                    v.erase(iter);
                    offset += 2;
                }
                else
                    offset += 1;
            }
        }

        cout << ans << endl;
    }

    return (0 ^ 0);
}
