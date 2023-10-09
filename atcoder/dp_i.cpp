// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <iomanip>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 3000;
int64_t n;
double p[maxn];
double dp[2][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cout << setprecision(12);

	cin >> n;
	for (int64_t i = 1; i <= n; i++)
		cin >> p[i];

	dp[1][0] = 1.0 - p[1];
	dp[1][1] = p[1];
	for (int64_t i = 2; i <= n; i++)
	{
		dp[i % 2][0] = dp[(i - 1) % 2][0] * (1.0 - p[i]);
		for (int64_t j = 1; j <= i; j++)
			dp[i % 2][j] = dp[(i - 1) % 2][j - 1] * p[i] + dp[(i - 1) % 2][j] * (1.0 - p[i]);
	}

	double result = 0.0;
	for (int64_t i = n; i > n / 2; i--)
		result += dp[1][i];
	cout << result << '\n';

	return (0 ^ 0);
}