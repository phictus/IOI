// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <random>
#include <map>
#include <cstdint>

using namespace std;

struct Vec2
{
    int64_t x, y;

    bool operator<(const Vec2& other) const
    {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }

    Vec2 operator+(const Vec2& other) const
    {
        return {x + other.x, y + other.y};
    }

    Vec2 operator-(const Vec2& other) const
    {
        return {x - other.x, y - other.y};
    }
};

constexpr int64_t maxn = 100000, tryCount = 5;
int64_t n;
Vec2 a, b, c[maxn];

bool IsCapturePossible(const Vec2& start, const Vec2& target)
{
    map<Vec2, int64_t> m;

    for (int64_t i = 0; i < n; i++)
        m[start + c[i]]++;

    if (m[target] > 0)
        return true;

    for (int64_t i = 0; i < n; i++)
    {
        Vec2 mid = target - c[i];
        if (mid.x >= 1 && mid.x <= n &&
            mid.y >= 1 && mid.y <= n &&
            m[mid] > 0)
            return true;
    }

    return false;
}

bool CheckAllPossibilities()
{
    map<Vec2, int64_t> m;

    for (int64_t i = 0; i < n; i++)
    {
        m[b + c[i]]++;
        for (int64_t j = i; j < n; j++)
            m[b + c[i] + c[j]]++;
    }

    int64_t count = 0;
    for (const auto&[k, v] : m)
    {
        if ((k.x != b.x || k.y != b.y) &&
            k.x >= 1 && k.x <= n &&
            k.y >= 1 && k.y <= n)
            count++;
    }

    return count == n * n - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    for (int64_t i = 0; i < n; i++)
        cin >> c[i].x >> c[i].y;

    if (IsCapturePossible(a, b))
    {
        cout << "Alice wins\n";
        return (0 ^ 0);
    }
    if (n <= 3 && CheckAllPossibilities())
    {
        cout << "Bob wins\n";
        return (0 ^ 0);
    }

    auto rng = default_random_engine(random_device()());
    auto distribution = uniform_int_distribution<int64_t>(1, n);
    for (int64_t t = 0; t < tryCount; t++)
    {
        Vec2 target = {distribution(rng), distribution(rng)};
        if ((target.x != b.x || target.y != b.y) && !IsCapturePossible(b, target))
        {
            cout << "tie " << target.x << ' ' << target.y << '\n';
            break;
        }
    }

    return (0 ^ 0);
}
