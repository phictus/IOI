// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <queue>
#include <cstdint>

using namespace std;

constexpr uint32_t maxn = 200001;
uint32_t n, m;
vector<uint32_t> adj[maxn];
vector<bool> isVisited;
uint32_t dist[maxn];
uint32_t result[maxn];

void InitDist()
{
	queue<uint32_t> q;

	q.push(1);
	isVisited[1] = true;
	dist[1] = 0;

	while (!q.empty())
	{
		uint32_t v = q.front();
		q.pop();

		for (uint32_t u : adj[v])
		{
			if (!isVisited[u])
			{
				q.push(u);
				isVisited[u] = true;
				dist[u] = dist[v] + 1;
			}
		}
	}
}

void InitResult(uint32_t v = 1)
{
	isVisited[v] = true;

	result[v] = dist[v];
	for (uint32_t u : adj[v])
	{
		if (!isVisited[u] && dist[v] < dist[u])
			InitResult(u);

		if (dist[v] < dist[u])
			result[v] = min(result[v], result[u]);
		else
			result[v] = min(result[v], dist[u]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	uint32_t t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;

		for (uint32_t i = 1; i <= n; i++)
			adj[i].clear();

		for (uint32_t i = 1; i <= m; i++)
		{
			uint32_t v, u;
			cin >> v >> u;
			adj[v].push_back(u);
		}

		isVisited = vector<bool>(n + 1, false);
		InitDist();
		isVisited = vector<bool>(n + 1, false);
		InitResult();

		for (uint32_t i = 1; i <= n; i++)
			cout << result[i] << ' ';
		cout << '\n';
	}

	return (0 ^ 0);
}