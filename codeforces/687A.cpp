// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

enum class Color : uint8_t
{
    Uncolored = 0,
    Red = 1,
    Blue = 2
};

constexpr uint32_t maxn = 100001;
uint32_t n, m;
uint32_t r = 0, b = 0;
vector<uint32_t> graph[maxn];
Color color[maxn];

void dfs(uint32_t v, uint32_t parent)
{
    if (!parent)
    {
        color[v] = Color::Red;
        r++;
    }
    else
    {
        if (color[parent] == Color::Blue)
        {
            color[v] = Color::Red;
            r++;
        }
        else
        {
            color[v] = Color::Blue;
            b++;
        }
    }

    for (uint32_t e : graph[v])
    {
        if (color[e] == color[v])
        {
            cout << "-1" << endl;
            exit(0);
        }

        if (color[e] == Color::Uncolored)
            dfs(e, v);
    }
}

void print(Color c)
{
    for (uint32_t i = 1; i <= n; i++)
        if (color[i] == c)
            cout << i << ' ';
    cout << endl;
}

int main()
{
    cin >> n >> m;
    for (uint32_t i = 0; i < m; i++)
    {
        uint32_t u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(color, 0, n * sizeof(Color));

    for (uint32_t i = 1; i <= n; i++)
        if (color[i] == Color::Uncolored)
            dfs(i, 0);

    cout << r << endl;
    print(Color::Red);
    cout << b << endl;
    print(Color::Blue);

    return (0 ^ 0);
}
