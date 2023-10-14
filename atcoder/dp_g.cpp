// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint>

using namespace std;

constexpr uint64_t maxn = 100001;
uint64_t n, m;
vector<int64_t> adj[maxn];
bool isVisited[maxn];
int64_t dp[maxn];

void dfs(int64_t v)
{
	isVisited[v] = true;

	for (int64_t u : adj[v])
	{
		if (!isVisited[u])
			dfs(u);

		dp[v] = max(dp[v], dp[u] + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int64_t i = 1; i <= m; i++)
	{
		int64_t v, u;
		cin >> v >> u;
		adj[v].push_back(u);
	}

	memset(isVisited, 0, (n + 1) * sizeof(bool));
	memset(dp, 0, (n + 1) * sizeof(int64_t));

	for (int64_t i = 1; i <= n; i++)
	{
		if (!isVisited[i])
			dfs(i);
	}

	int64_t result = 0;
	for (int64_t i = 1; i <= n; i++)
		result = max(result, dp[i]);
	cout << result << '\n';

	return (0 ^ 0);
}