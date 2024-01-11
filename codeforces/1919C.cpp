// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <limits>
#include <cstdint>

using namespace std;
constexpr int64_t inf = numeric_limits<int64_t>::max();

void SolveTestCase()
{
    int64_t n;
    cin >> n;

    vector<int64_t> a = {inf}, b = {inf};
    for (int64_t i = 0; i < n; i++)
    {
        int64_t x;
        cin >> x;
        if (x > a.back())
        {
            if (x > b.back())
            {
                if (a.back() < b.back())
                    a.push_back(x);
                else
                    b.push_back(x);
            }
            else
                b.push_back(x);
        }
        else
        {
            if (x > b.back())
                a.push_back(x);
            else
            {
                if (a.back() < b.back())
                    a.push_back(x);
                else
                    b.push_back(x);
            }
        }
    }

    int64_t result = 0;
    for (int64_t i = 1; i < a.size(); i++)
        if (a[i - 1] < a[i])
            result++;
    for (int64_t i = 1; i < b.size(); i++)
        if (b[i - 1] < b[i])
            result++;
    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
        SolveTestCase();

    return (0 ^ 0);
}
