// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <map>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

void SolveTestCase()
{
    int64_t a, b, xk, yk, xq, yq;
    cin >> a >> b;
    cin >> xk >> yk;
    cin >> xq >> yq;

    vector<int64_t> dx, dy;
    dx.push_back(a);
    dy.push_back(b);
    dx.push_back(-a);
    dy.push_back(b);
    dx.push_back(a);
    dy.push_back(-b);
    dx.push_back(-a);
    dy.push_back(-b);
    if (a != b)
    {
        dx.push_back(b);
        dy.push_back(a);
        dx.push_back(-b);
        dy.push_back(a);
        dx.push_back(b);
        dy.push_back(-a);
        dx.push_back(-b);
        dy.push_back(-a);
    }

    map<Pair, int64_t> m;
    for (int64_t i = 0; i < dx.size(); i++)
    {
        m[make_pair(xk + dx[i], yk + dy[i])]++;
        m[make_pair(xq + dx[i], yq + dy[i])]++;
    }

    int64_t result = 0;
    for (auto[k, v] : m)
    {
        if (v > 1)
            result++;
    }
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
