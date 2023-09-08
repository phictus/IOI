// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    uint32_t k;
    cin >> k;

    if (k % 2 == 0)
        cout << "NO\n";
    else if (k == 1)
        cout << "YES\n2 1\n1 2\n";
    else
    {
        vector<pair<uint32_t, uint32_t>> edges;
        for (uint32_t i = 4; i <= k + 2; i++)
            edges.push_back(make_pair(1, i));

        edges.push_back(make_pair(2, 3));

        for (uint32_t i = 2; i <= k + 2; i += 2)
            for (uint32_t j = i + 2; j <= k + 2; j++)
                edges.push_back(make_pair(i, j));

        for (uint32_t i = 3; i <= k + 2; i += 2)
            for (uint32_t j = i + 1; j <= k + 2; j++)
                edges.push_back(make_pair(i, j));

        cout << "YES\n";
        cout << 2 * k + 4 << ' ' << 2 * edges.size() + 1 << '\n';

        cout << 1 << ' ' << k + 3 << '\n';
        for (auto[v, u] : edges)
            for (uint32_t i = 0; i <= k + 2; i += k + 2)
                cout << v + i << ' ' << u + i << '\n';
    }

    return (0 ^ 0);
}
