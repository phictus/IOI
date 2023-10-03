// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100000;
int64_t n;
int32_t h[maxn][3];
int64_t dp[maxn][3];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int64_t i = 0; i < n; i++)
	{
		for (int64_t j = 0; j < 3; j++)
			cin >> h[i][j];
	}

	for (int64_t i = 0; i < 3; i++)
		dp[0][i] = h[0][i];

	for (int64_t i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + h[i][0];
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + h[i][1];
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + h[i][2];
	}

	int64_t result = 0;
	for (int64_t i = 0; i < 3; i++)
		result = max(result, dp[n - 1][i]);
	cout << result << '\n';

	return (0 ^ 0);
}