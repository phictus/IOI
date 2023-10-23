// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

int64_t n, k;
string s;
int64_t cnt[26];

inline int64_t GetID(char c)
{
    return (int64_t)(c - 'a');
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;

        for (int64_t i = 0; i < 26; i++)
            cnt[i] = 0;
        for (char c : s)
            cnt[GetID(c)]++;

        int64_t oddCount = 0;
        for (int64_t i = 0; i < 26; i++)
        {
            if (cnt[i] % 2 == 1)
                oddCount++;
        }

        if (oddCount - 1 <= k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return (0 ^ 0);
}
