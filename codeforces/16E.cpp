// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <iomanip>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 18;
int64_t n;
double p[maxn][maxn], dp[1 << maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cout << setprecision(12);

	cin >> n;
	for (int64_t i = 0; i < n; i++)
	{
		for (int64_t j = 0; j < n; j++)
			cin >> p[i][j];
	}

	dp[(1 << n) - 1] = 1.0;
	for (int64_t mask = (1 << n) - 2; mask > 0; mask--)
	{
		for (int64_t dead = 0; dead < n; dead++)
		{
			if (((mask >> dead) & 1) == 1)
				continue;

			int64_t oneCount = 0;
			double deathProbability = 0.0;
			for (int64_t alive = 0; alive < n; alive++)
			{
				if (((mask >> alive) & 1) == 0)
					continue;

				oneCount++;
				deathProbability += dp[mask + (1 << dead)] * p[alive][dead];
			}

			dp[mask] += (2.0 * deathProbability) / ((oneCount + 1) * oneCount);
		}
	}

	for (int64_t i = 0; i < n; i++)
		cout << dp[1 << i] << '\n';

	return (0 ^ 0);
}