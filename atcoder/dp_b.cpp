// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100001;
int64_t n, k;
int64_t h[maxn];
int64_t dp[maxn];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for (int64_t i = 1; i <= n; i++)
		cin >> h[i];

	dp[1] = 0;
	for (int64_t i = 2; i <= n; i++)
	{
		dp[i] = numeric_limits<int64_t>::max();
		for (int64_t j = i - 1; j + k >= i && j >= 1; j--)
			dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
	}
	cout << dp[n] << '\n';

	return (0 ^ 0);
}