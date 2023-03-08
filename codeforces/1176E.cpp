// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

enum class State : uint8_t
{
    NotVisited = 0,
    Chosen = 1,
    NotChosen = 2
};

inline State operator!(State s)
{
    if (s == State::Chosen)
        return State::NotChosen;
    else if (s == State::NotChosen)
        return State::Chosen;
    else
        return State::NotVisited;
}

constexpr uint32_t maxn = 200001;
uint32_t n, m;
State state[maxn];
uint32_t numberOfChosen;

void dfs(vector<uint32_t>* graph, uint32_t vertex, State vertexState)
{
    state[vertex] = vertexState;
    if (vertexState == State::Chosen)
        numberOfChosen++;

    for (uint32_t adjacent : graph[vertex])
        if (state[adjacent] == State::NotVisited)
            dfs(graph, adjacent, !vertexState);
}

int main()
{
    uint32_t t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(state, 0, (n + 1) * sizeof(State));
        numberOfChosen = 0;
        vector<uint32_t> graph[n + 1];
        for (uint32_t i = 0; i < m; i++)
        {
            uint32_t u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(graph, 1, State::Chosen);

        State s;
        if (numberOfChosen <= n / 2)
        {
            cout << numberOfChosen << endl;
            s = State::Chosen;
        }
        else
        {
            cout << n - numberOfChosen << endl;
            s = State::NotChosen;
        }
        for (uint32_t i = 1; i <= n; i++)
            if (state[i] == s)
                cout << i << ' ';
        cout << endl;
    }

    return (0 ^ 0);
}
