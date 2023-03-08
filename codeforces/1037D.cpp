// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

constexpr uint32_t maxn = 200001;
uint32_t n;
vector<uint32_t> graph[maxn];
uint32_t bfsSequence[maxn];
bool visited[maxn];

inline void notValid()
{
    cout << "No" << endl;
    exit(0);
}

void bfs()
{
    if (bfsSequence[0] != 1)
        notValid();

    queue<uint32_t> q;
    q.push(bfsSequence[0]);
    visited[bfsSequence[0]] = true;
    uint32_t k = 1;

    while (!q.empty())
    {
        uint32_t vertex = q.front();
        q.pop();

        sort(graph[vertex].begin(), graph[vertex].end());
        for (uint32_t i = k; i < k + graph[vertex].size(); i++)
        {
            if (!visited[bfsSequence[i]])
            {
                if (!binary_search(graph[vertex].begin(), graph[vertex].end(), bfsSequence[i]))
                    notValid();
                else
                {
                    q.push((bfsSequence[i]));
                    visited[bfsSequence[i]] = true;
                }
            }
        }

        k += graph[vertex].size() - 1;
    }
}

int main()
{
    cin >> n;
    for (uint32_t i = 1; i < n; i++)
    {
        uint32_t u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (uint32_t i = 0; i < n; i++)
        cin >> bfsSequence[i];

    memset(visited, 0, (n + 1) * sizeof(bool));
    bfs();
    cout << "Yes" << endl;

    return (0 ^ 0);
}
