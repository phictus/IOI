// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int64_t t;
	cin >> t;
	while (t--)
	{
		int64_t n;
		cin >> n;

		int64_t result = 0;
		for (int64_t i = 1; i < n; i++)
		{
			int64_t x;
			cin >> x;
			result += x;
		}

		cout << -result << '\n';
	}

	return (0 ^ 0);
}