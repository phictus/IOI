// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200001;
int64_t n, value[maxn], sum[maxn], dp[maxn][2];
vector<int64_t> adj[maxn];

void GetSum(int64_t v = 1, int64_t p = 0)
{
	sum[v] = value[v];
	for (int64_t u : adj[v])
	{
		if (u != p)
		{
			GetSum(u, v);
			sum[v] += sum[u];
		}
	}
}

void GetDp0(int64_t v = 0, int64_t p = 0)
{
	dp[v][0] = 0;
	for (int64_t u : adj[v])
	{
		if (u != p)
		{
			GetDp0(u, v);
			dp[v][0] += dp[u][0] + sum[u];
		}
	}
}

void GetDp1(int64_t v = 1, int64_t p = 0)
{
	dp[v][1] = dp[p][1] + dp[p][0] - (dp[v][0] + sum[v]) + (sum[1] - sum[v]);

	for (int64_t u : adj[v])
	{
		if (u != p)
			GetDp1(u, v);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int64_t i = 1; i <= n; i++)
		cin >> value[i];
	for (int64_t i = 1; i < n; i++)
	{
		int64_t v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	adj[0].push_back(1);
	dp[0][1] = 0;

	GetSum();
	GetDp0();
	GetDp1();

	int64_t result = 0;
	for (int64_t i = 1; i <= n; i++)
		result = max(result, dp[i][0] + dp[i][1]);
	cout << result << '\n';

	return (0 ^ 0);
}