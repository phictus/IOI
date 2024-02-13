// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 300001, mod = 1000000007;
int64_t n, power[maxn];

class PalindromeTree
{
public:
    void SetValue(int64_t index, int64_t value, int64_t idl = 1, int64_t idr = n + 1, int64_t id = 1)
    {
        if (idl + 1 == idr)
        {
            _hash[id] = value;
            _reverseHash[id] = value;
            return;
        }

        int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
        if (index < mid)
            SetValue(index, value, idl, mid, lc);
        else
            SetValue(index, value, mid, idr, rc);

        _hash[id] = (_hash[lc] + (power[mid - idl] * _hash[rc]) % mod) % mod;
        _reverseHash[id] = ((power[idr - mid] * _reverseHash[lc]) % mod + _reverseHash[rc]) % mod;
    }

    bool IsPalindrome(int64_t l, int64_t r)
    {
        return _GetHash(l, r).value == _GetReverseHash(l, r).value;
    }

private:
    struct _Result
    {
        int64_t value = 0;
        int64_t length = 0;
    };

    _Result _GetHash(int64_t l, int64_t r, int64_t idl = 1, int64_t idr = n + 1, int64_t id = 1)
    {
        if (idl >= r || idr <= l)
            return _Result();
        if (idl >= l && idr <= r)
            return {_hash[id], idr - idl};

        int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
        _Result lResult = _GetHash(l, r, idl, mid, lc);
        _Result rResult = _GetHash(l, r, mid, idr, rc);

        return {
            (lResult.value + (power[lResult.length] * rResult.value) % mod) % mod,
            lResult.length + rResult.length
        };
    }

    _Result _GetReverseHash(int64_t l, int64_t r, int64_t idl = 1, int64_t idr = n + 1, int64_t id = 1)
    {
        if (idl >= r || idr <= l)
            return _Result();
        if (idl >= l && idr <= r)
            return {_reverseHash[id], idr - idl};

        int64_t mid = (idl + idr) / 2, lc = 2 * id, rc = 2 * id + 1;
        _Result lResult = _GetReverseHash(l, r, idl, mid, lc);
        _Result rResult = _GetReverseHash(l, r, mid, idr, rc);

        return {
            ((power[rResult.length] * lResult.value) % mod + rResult.value) % mod,
            lResult.length + rResult.length
        };
    }

    int64_t _hash[4 * maxn], _reverseHash[4 * maxn];

} tree;

int main()
{
    ios_base::sync_with_stdio(false);

    power[0] = 1;
    for (int64_t i = 1; i < maxn; i++)
        power[i] = (2 * power[i - 1]) % mod;

    cin >> n;
    for (int64_t i = 0; i < n; i++)
    {
        int64_t a;
        cin >> a;
        tree.SetValue(a, 1);

        int64_t dist = min(a - 1, n - a);
        if (!tree.IsPalindrome(a - dist, a + dist + 1))
        {
            cout << "YES\n";
            return (0 ^ 0);
        }
    }

    cout << "NO\n";
    return (0 ^ 0);
}
