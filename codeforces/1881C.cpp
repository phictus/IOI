// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 1000;
char grid[maxn][maxn];

int64_t getDiff(char a, char b, char c, char d)
{
	const int64_t arr[] = { a, b, c, d };

	int64_t sum = 0, maximum = 0;
	for (int64_t i = 0; i < 4; i++)
	{
		sum += arr[i];
		maximum = max(maximum, arr[i]);
	}

	return 4 * maximum - sum;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int64_t t;
	cin >> t;
	while (t--)
	{
		int64_t n;
		cin >> n;
		for (int64_t i = 0; i < n; i++)
			for (int64_t j = 0; j < n; j++)
				cin >> grid[i][j];

		int64_t result = 0;
		for (int64_t i = 0; i < n / 2; i++)
			for (int64_t j = 0; j < n / 2; j++)
				result += getDiff(grid[i][j], grid[n - j - 1][i], grid[n - i - 1][n - j - 1], grid[j][n - i -  1]);

		cout << result << '\n';
	}

	return (0 ^ 0);
}