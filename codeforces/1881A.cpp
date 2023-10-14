// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

constexpr int64_t impossible = numeric_limits<int64_t>::max();
int64_t n, m;
string x, s;

int64_t getResult(int64_t start)
{
	string y = x;
	int64_t result = 0;
	int64_t i = start, j = 0;
	while (true)
	{
		if (y[i] != s[j])
			return impossible;

		i++;
		j++;

		if (j == m)
			return result;

		if (i == y.size())
		{
			y += y;
			result++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	int64_t t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		cin >> x >> s;

		int64_t result = impossible;
		for (int64_t i = 0; i < n; i++)
			result = min(result, getResult(i));
		cout << (result == impossible ? -1 : result) << '\n';
	}

	return (0 ^ 0);
}