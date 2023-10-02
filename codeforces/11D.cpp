// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int32_t maxn = 19;
int32_t n, m;
bool isAdjacent[maxn][maxn];
int64_t dp[1 << maxn][maxn];

inline int32_t OneBitCount(int32_t x)
{
	int32_t result = 0;
	for (int32_t i = 0; i < n; i++)
	{
		if ((x >> i) & 1)
			result++;
	}

	return result;
}

void UpdateDP(int32_t s, int32_t v, int32_t u)
{
	int32_t oneBitCount = OneBitCount(s);
	if (v == u)
		dp[s][v] = 0;
	else if (oneBitCount == 2)
		dp[s][v] = isAdjacent[v][u] ? 1 : 0;
	else
	{
		dp[s][v] = 0;
		for (int32_t i = 0; i < n; i++)
		{
			if (((s >> i) & 1) && isAdjacent[v][i] && i != u)
				dp[s][v] += dp[s - (1 << v)][i];
		}
	}
}

int64_t GetResult()
{
	int64_t result = 0;
	for (int32_t i = 0; i < (1 << n); i++)
	{
		int32_t lsb = -1;
		for (int32_t j = 0; j < n; j++)
		{
			if (((i >> j) & 1))
			{
				if (lsb < 0)
					lsb = j;
				if (isAdjacent[lsb][j])
					result += dp[i][j];
			}
		}
	}

	return (result - m) / 2;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int32_t i = 0; i < m; i++)
	{
		int32_t v, u;
		cin >> v >> u;
		isAdjacent[v - 1][u - 1] = true;
		isAdjacent[u - 1][v - 1] = true;
	}

	for (int32_t i = 0; i < (1 << n); i++)
	{
		int32_t lsb = -1;
		for (int32_t j = 0; j < n; j++)
		{
			if ((i >> j) & 1)
			{
				if (lsb < 0)
					lsb = j;
				UpdateDP(i, j, lsb);
			}
		}
	}

	cout << GetResult() << '\n';

	return (0 ^ 0);
}