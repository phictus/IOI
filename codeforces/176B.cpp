// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

constexpr uint64_t mod = 1000000007;

void FindOffsets(const string& str1, const string& str2, vector<uint64_t>& offsets)
{
    deque<char> l;
    for (char c : str1)
        l.push_back(c);

    for (uint64_t offset = 0; offset < str1.size(); offset++)
    {
        bool isEqual = true;
        for (uint64_t i = 0; i < str1.size(); i++)
            if (l[i] != str2[i])
                goto NOT_EQUAL;
        offsets.push_back(offset);

    NOT_EQUAL:
        uint64_t x = l.back();
        l.pop_back();
        l.push_front(x);
    }
}

int main()
{
    string str1, str2;
    uint64_t k;
    cin >> str1 >> str2 >> k;

    vector<uint64_t> offsets;
    FindOffsets(str1, str2, offsets);
    if (offsets.empty() || str1.size() != str2.size())
    {
        cout << 0 << endl;
        return (0 ^ 0);
    }

    uint64_t sum = 1;
    uint64_t dp[str1.size()];

    dp[0] = 1;
    for (uint64_t i = 1; i < str1.size(); i++)
        dp[i] = 0;

    for (uint64_t i = 0; i < k; i++)
    {
        for (uint64_t j = 0; j < str1.size(); j++)
            dp[j] = ((sum + mod) - dp[j]) % mod;

        sum = 0;
        for (uint64_t j = 0; j < str1.size(); j++)
        {
            sum += dp[j];
            sum %= mod;
        }
    }


    uint64_t result = 0;
    for (uint64_t offset : offsets)
    {
        result += dp[offset];
        result %= mod;
    }
    cout << result << endl;

    return (0 ^ 0);
}
