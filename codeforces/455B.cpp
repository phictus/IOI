// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

struct Trie
{
    Trie* next[26];
    bool canWin = false, canLose = false;

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
        Trie* v = this;
        for (char c : s)
        {
            if (!v->next[c - 'a'])
                v->next[c - 'a'] = new Trie();
            v = v->next[c - 'a'];
        }
    }
} trie;


void GetResult(Trie* v)
{
    bool isLeaf = true;
    for (int64_t i = 0; i < 26; i++)
    {
        if (v->next[i])
        {
            isLeaf = false;
            break;
        }
    }
    if (isLeaf)
    {
        v->canLose = true;
        return;
    }

    for (int64_t i = 0; i < 26; i++)
    {
        Trie* u = v->next[i];
        if (u)
        {
            GetResult(u);
            if (!u->canWin)
                v->canWin = true;
            if (!u->canLose)
                v->canLose = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t n, k;
    cin >> n >> k;
    for (int64_t i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        trie.Add(s);
    }

    GetResult(&trie);
    if (trie.canWin && (trie.canLose || k % 2 == 1))
        cout << "First\n";
    else
        cout << "Second\n";

    return (0 ^ 0);
}
