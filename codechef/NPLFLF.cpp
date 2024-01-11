// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <algorithm>
#include <set>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100000;
string cache[maxn + 1];
multiset<int64_t> dp[maxn + 1];

struct Trie
{
    Trie* next[26];
    int64_t cnt = 0;

    ~Trie()
    {
        for (int64_t i = 0; i < 26; i++)
        {
            if (!next[i])
            {
                delete next[i];
                next[i] = nullptr;
            }
        }
    }

    void Add(const string& s)
    {
        Trie* current = this;
        int64_t depth = 0;
        for (char c : s)
        {
            if (!current->next[c - 'a'])
                current->next[c - 'a'] = new Trie();
            current = current->next[c - 'a'];

            depth++;
            if (current->cnt > 0)
                dp[depth].erase(dp[depth].find(current->cnt));
            dp[depth].insert(++current->cnt);
        }
    }

    void Remove(const string& s)
    {
        Trie* current = this;
        int64_t depth = 0;
        for (char c : s)
        {
            current = current->next[c - 'a'];

            depth++;
            dp[depth].erase(dp[depth].find(current->cnt--));
            if (current->cnt > 0)
                dp[depth].insert(current->cnt);
        }
    }

} trie;

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t q;
    cin >> q;
    for (int64_t i = 1; i <= q; i++)
    {
        int64_t type;
        cin >> type;
        if (type == 1)
        {
            cin >> cache[i];
            reverse(cache[i].begin(), cache[i].end());
            trie.Add(cache[i]);
        }
        else if (type == 2)
        {
            int64_t k, l;
            cin >> k >> l;
            if (!dp[l].empty() && *dp[l].rbegin() >= k)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            int64_t x;
            cin >> x;
            if (!cache[x].empty())
                trie.Remove(cache[x]);
            cache[x].clear();
        }
    }

    return (0 ^ 0);
}
