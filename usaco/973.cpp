// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <vector>
#include <map>
#include <cstdint>

using namespace std;
constexpr int64_t maxn = 100001;

class Fenwick
{
public:
    void Update(int64_t index, int64_t value)
    {
        while (index < maxn)
        {
            _data[index] += value;
            index += index & -index;
        }
    }

    int64_t Get(int64_t l, int64_t r)
    {
        return _GetSum(r) - _GetSum(l - 1); 
    }

private:
    int64_t _GetSum(int64_t index)
    {
        int64_t sum = 0;
        while (index > 0)
        {
            sum += _data[index];
            index -= index & -index;
        }

        return sum;
    }

    int64_t _data[maxn];
} f1, f2;

int64_t n, q;
vector<int64_t> adj[maxn];
int64_t currentTime = 0, s[maxn], e[maxn];
map<int64_t, int64_t> colorList[maxn];

void InitDiscovery(int64_t v = 1, int64_t p = 1)
{
    s[v] = ++currentTime;
    for (int64_t u : adj[v])
        if (u != p)
            InitDiscovery(u, v);
    e[v] = currentTime;
}

int main()
{
    ios_base::sync_with_stdio(false);

    freopen("snowcow.in", "r", stdin);
    freopen("snowcow.out", "w", stdout);

    cin >> n >> q;
    for (int64_t i = 1; i < n; i++)
    {
        int64_t v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    InitDiscovery();

    for (int64_t i = 1; i <= q; i++)
    {
        int64_t type;
        cin >> type;
        if (type == 1)
        {
            int64_t v, c;
            cin >> v >> c;

            auto it = colorList[c].upper_bound(s[v]);
            if (it != colorList[c].begin() && e[prev(it)->second] >= e[v])
                continue;

            while (it != end(colorList[c]) && e[it->second] <= e[v]) {
                f1.Update(s[it->second], -1);
                f1.Update(e[it->second] + 1, 1);
                f2.Update(s[it->second], s[it->second] - e[it->second] - 1);

                colorList[c].erase(it++);
            }

            colorList[c][s[v]] = v;
            f1.Update(s[v], 1);
            f1.Update(e[v] + 1, -1);
            f2.Update(s[v], e[v] - s[v] + 1);
        }
        else
        {
            int64_t v;
            cin >> v;
            cout << (e[v] - s[v] + 1) * f1.Get(1, s[v]) + f2.Get(s[v] + 1, e[v]) << "\n";
        }
    }

    return (0 ^ 0);
}
