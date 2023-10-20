// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 20;
int64_t n, m;
int64_t pa[maxn], b[maxn];
int64_t dp[1 << maxn];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	cin >> pa[0];
	for (int64_t i = 1; i < n; i++)
	{
		cin >> pa[i];
		pa[i] += pa[i - 1];
	}
	for (int64_t i = 0; i < m; i++)
		cin >> b[i];

	dp[0] = -1;
	for (int64_t mask = 1; mask < (1 << m); mask++)
	{
		dp[mask] = -1;
		int64_t sum = 0;
		for (int64_t i = 0; i < m; i++)
		{
			if (((mask >> i) & 1) == 1)
			{
				dp[mask] = max(dp[mask], dp[mask - (1 << i)]);
				sum += b[i];
			}
		}

		if (sum == pa[dp[mask] + 1])
			dp[mask]++;
	}

	if (dp[(1 << m) - 1] == n - 1)
		cout << "YES\n";
	else
		cout << "NO\n";

	return (0 ^ 0);
}