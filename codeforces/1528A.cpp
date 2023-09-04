// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>

using namespace std;

constexpr int64_t maxn = 200001;
vector<int64_t> adjacents[maxn];
int64_t l[maxn], r[maxn];
int64_t maxl[maxn], maxr[maxn];

void DFS(int64_t v, int64_t p = 0)
{
    maxl[v] = 0;
    maxr[v] = 0;

    for (int64_t adj : adjacents[v])
    {
        if (adj != p)
        {
            DFS(adj, v);

            maxl[v] += max(
                abs(l[v] - l[adj]) + maxl[adj],
                abs(l[v] - r[adj]) + maxr[adj]
            );
            maxr[v] += max(
                abs(r[v] - l[adj]) + maxl[adj],
                abs(r[v] - r[adj]) + maxr[adj]
            );
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        int64_t n;
        cin >> n;
        for (int64_t i = 1; i <= n; i++)
        {
            cin >> l[i] >> r[i];
            adjacents[i].clear();
        }
        for (int64_t i = 1; i < n; i++)
        {
            int64_t v, u;
            cin >> v >> u;
            adjacents[v].push_back(u);
            adjacents[u].push_back(v);
        }

        DFS(1);
        cout << max(maxl[1], maxr[1]) << '\n';
    }

    return (0 ^ 0);
}
