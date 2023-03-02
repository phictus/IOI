// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int32_t t;
    cin >> t;
    while (t--)
    {
        int32_t n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        unordered_map<char, pair<int32_t, int32_t>> map;
        for (char c : str)
        {
            if (islower(c))
                map[tolower(c)].first++;
            else
                map[tolower(c)].second++;
        }

        for (auto& e : map)
        {
            if (k == 0)
                break;
            while (abs(e.second.first - e.second.second) > 1)
            {
                if (k == 0)
                    break;

                if (e.second.first > e.second.second)
                {
                    e.second.first--;
                    e.second.second++;
                    k--;
                }
                else
                {
                    e.second.first++;
                    e.second.second--;
                    k--;
                }
            }
        }

        int32_t ans = 0;
        for (auto e : map)
            ans += min(e.second.first, e.second.second);
        cout << ans << endl;
    }

    return (0 ^ 0);
}
