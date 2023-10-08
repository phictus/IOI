// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr uint64_t maxn = 1001, mod = 1000000007;
uint64_t n, m;
char grid[maxn][maxn];
uint64_t dp[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (uint64_t i = 1; i <= n; i++)
	{
		for (uint64_t j = 1; j <= m; j++)
			cin >> grid[i][j];
	}

	for (uint64_t i = 1; i <= n; i++)
		dp[i][0] = 0;
	for (uint64_t i = 2; i <= m; i++)
		dp[0][i] = 0;
	dp[0][1] = 1;

	for (uint64_t i = 1; i <= n; i++)
	{
		for (uint64_t j = 1; j <= m; j++)
		{
			if (grid[i][j] == '#')
				dp[i][j] = 0;
			else
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
		}
	}

	cout << dp[n][m] << '\n';

	return (0 ^ 0);
}