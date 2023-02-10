// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstring>

using namespace std;

enum class Color : uint8_t
{
    Red = 0,
    Green = 1,
    Blue = 2
};

constexpr uint32_t maxn = 2000001;
uint32_t n;
uint32_t parent[maxn];
Color color[maxn];
uint32_t root = 0;
uint32_t ans = 0;

void dfs(uint32_t v)
{
    color[v] = Color::Green;

    if (v == parent[v])
    {
        if (v != root)
        {
            parent[v] = root;
            ans++;
        }
    }
    else if (color[parent[v]] == Color::Green)
    {
        if (root == 0)
            root = v;
        parent[v] = root;
        ans++;
    }
    else if (color[parent[v]] == Color::Red)
        dfs(parent[v]);

    color[v] = Color::Blue;
}

int main()
{
    cin >> n;
    for (uint32_t i = 1; i <= n; i++)
    {
        cin >> parent[i];
        if (root == 0 && parent[i] == i)
            root = i;
    }

    memset(color, 0, n * sizeof(Color));
    for (uint32_t i = 1; i <= n; i++)
        if (color[i] == Color::Red)
            dfs(i);

    cout << ans << endl;
    for (uint32_t i = 1; i <= n; i++)
        cout << parent[i] << ' ';
    cout << endl;

    return (0 ^ 0);
}
