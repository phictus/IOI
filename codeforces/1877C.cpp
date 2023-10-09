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
		int64_t n, m, k;
		cin >> n >> m >> k;

		if (k == 1)
			cout << "1\n";
		else if (k == 2)
			cout << (m / n) + min(m, n - 1) << '\n';
		else if (k == 3)
		{
			if (m <= n || n == 1)
				cout << "0\n";
			else
				cout << m - n + 1 - (m / n) << '\n';
		}
		else
			cout << "0\n";
	}

	return (0 ^ 0);
}