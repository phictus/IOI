// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>
#include <algorithm>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 100001;
int64_t n, p;
Pair value[maxn];

inline int64_t FindMin()
{
	int64_t result = numeric_limits<int64_t>::max();
	for (int64_t i = 1; i <= n; i++)
		result = min(result, value[i].first);

	return result;
}

int64_t GetResult()
{
	value[0].first = p;
	value[0].second = n - 1;
	sort(value, value + n + 1);

	int64_t result = p, count = 2;
	for (int64_t i = 0; i < n && count <= n; i++)
	{
		int64_t t = min(value[i].second, n + 1 - count);
		result += value[i].first * t;
		count += t;
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int64_t t;
	cin >> t;
	while (t--)
	{
		cin >> n >> p;
		for (int64_t i = 1; i <= n; i++)
			cin >> value[i].second;
		for (int64_t i = 1; i <= n; i++)
			cin >> value[i].first;

		int64_t m = FindMin();
		if (p <= m)
			cout << n * p << '\n';
		else
			cout << GetResult() << '\n';
	}

	return (0 ^ 0);
}