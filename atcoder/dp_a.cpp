// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100001;
int64_t n;
int64_t h[maxn];
int64_t dp[maxn];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int64_t i = 1; i <= n; i++)
		cin >> h[i];

	dp[1] = 0;
	dp[2] = abs(h[2] - h[1]);
	for (int64_t i = 3; i <= n; i++)
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
	cout << dp[n] << '\n';

	return (0 ^ 0);
}