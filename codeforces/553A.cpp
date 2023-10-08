// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr uint64_t mod = 1000000007;

uint64_t Power(int32_t base, int32_t power)
{
	if (power == 0)
		return 1;

	uint64_t result = Power(base, power / 2);
	result = (result * result) % mod;

	if (power % 2 == 0)
		return result;
	else
		return (result * base) % mod;
}

uint64_t Choose(int32_t n, int32_t k)
{
	if (k > n)
		return 0;
	if (k > n / 2)
		k = n - k;

	uint64_t result = 1;
	for (uint64_t i = n - k + 1; i <= n; i++)
		result = (result * i) % mod;
	for (uint64_t i = 1; i <= k; i++)
		result = (result * Power(i, mod - 2)) % mod;

	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);

	int32_t n;
	cin >> n;
	int32_t c[n];
	for (int32_t i = 0; i < n; i++)
		cin >> c[i];

	uint64_t result = 1;
	int32_t count = c[0];
	for (int32_t i = 1; i < n; i++)
	{
		result = (result * Choose(count + c[i] - 1, count)) % mod;
		count += c[i];
	}

	cout << result << '\n';

	return (0 ^ 0);
}
