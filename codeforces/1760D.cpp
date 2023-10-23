// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

constexpr int64_t inf = numeric_limits<int64_t>::max();
constexpr int64_t maxn = 200001;
int64_t n, a[maxn];

enum class State
{
    Increasing,
    Decreasing
};

int main()
{
    int64_t t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int64_t i = 0; i < n; i++)
            cin >> a[i];
        a[n] = inf;

        int64_t result = 0;
        State state = State::Decreasing;
        for (int64_t i = 0; i < n; i++)
        {
            if (a[i] < a[i + 1])
            {
                if (state == State::Decreasing)
                    result++;
                state = State::Increasing;
            }
            else if (a[i] > a[i + 1])
            {
                state = State::Decreasing;
            }
        }

        if (result == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return (0 ^ 0);
}
