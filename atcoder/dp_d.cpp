// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 101, maxw = 100001;
int64_t n, w;
int64_t weight[maxn], value[maxn];
int64_t dp[maxn][maxw];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> w;
	for (int64_t i = 1; i <= n; i++)
		cin >> weight[i] >> value[i];

	for (int64_t i = 1; i <= w; i++)
		dp[0][i] = 0;
	for (int64_t i = 1; i <= n; i++)
	{
		for (int64_t j = 1; j <= w; j++)
		{
			if (weight[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
		}
	}
	

	cout << dp[n][w] << '\n';

	return (0 ^ 0);
}