// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 501;
int64_t n, m, b, mod;
int64_t a[maxn];
int64_t dp[2][maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> b >> mod;
	for (int64_t i = 1; i <= n; i++)
		cin >> a[i];

	for (int64_t i = 0; i <= b; i++)
		dp[0][0][i] = 1;
	for (int64_t i = 1; i <= m; i++)
	{
		for (int64_t j = 0; j <= b; j++)
			dp[0][i][j] = 0;
	}

	for (int64_t i = 1; i <= n; i++)
	{
		for (int64_t j = 0; j <= b; j++)
			dp[i % 2][0][j] = 1;

		for (int64_t j = 1; j <= m; j++)
		{
			for (int64_t k = 0; k < a[i]; k++)
				dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];

			for (int64_t k = a[i]; k <= b; k++)
				dp[i % 2][j][k] = (dp[(i - 1) % 2][j][k] + dp[i % 2][j - 1][k - a[i]]) % mod;
		}
	}

	cout << dp[n % 2][m][b] << '\n';

	return (0 ^ 0);
}