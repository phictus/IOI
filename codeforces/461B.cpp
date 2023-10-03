// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

constexpr uint64_t maxn = 100000, mod = 1000000007;
uint64_t n;
vector<uint64_t> children[maxn];
bool isBlack[maxn];

struct Result
{
	uint64_t X, Y;
};

Result GetResult(uint64_t v)
{
	Result vResult;
	vResult.X = isBlack[v] ? 1 : 0;
	vResult.Y = isBlack[v] ? 0 : 1;

	for (uint64_t u : children[v])
	{
		Result uResult = GetResult(u);

		vResult.X = (vResult.X * ((uResult.X + uResult.Y) % mod)) % mod;
		vResult.X = (vResult.X + ((uResult.X * vResult.Y) % mod)) % mod;
		vResult.Y = (vResult.Y * ((uResult.X + uResult.Y) % mod)) % mod;
	}

	return vResult;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (uint64_t u = 1; u < n; u++)
	{
		uint64_t v;
		cin >> v;
		children[v].push_back(u);
	}
	for (uint64_t v = 0; v < n; v++)
		cin >> isBlack[v];

	cout << GetResult(0).X << '\n';

	return (0 ^ 0);
}