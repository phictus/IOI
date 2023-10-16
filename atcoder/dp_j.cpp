// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <iomanip>
#include <cstdint>

using namespace std;

int64_t n;
int64_t c[4] = { 0, 0, 0, 0 };
double e[302][302][302];

#define d(x) (double)(x)

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int64_t i = 1; i <= n; i++)
	{
		int64_t p;
		cin >> p;
		c[p]++;
	}

	for (int64_t x3 = 0; x3 <= 300; x3++)
	{
		for (int64_t x2 = 0; x2 <= 300; x2++)
		{
			for (int64_t x1 = 0; x1 <= 300; x1++)
			{
				const double e1 = x1 == 0 ? 0.0 : d(x1) * e[x1 - 1][x2][x3];
				const double e2 = x2 == 0 ? 0.0 : d(x2) * e[x1 + 1][x2 - 1][x3];
				const double e3 = x3 == 0 ? 0.0 : d(x3) * e[x1][x2 + 1][x3 - 1];

				e[x1][x2][x3] = x1 == 0 && x2 == 0 && x3 == 0 ? 0.0 : (d(n) + e1 + e2 + e3) / d(x1 + x2 + x3);
			}
		}
	}

	cout << setprecision(12) << e[c[1]][c[2]][c[3]] << '\n';

	return (0 ^ 0);
}
