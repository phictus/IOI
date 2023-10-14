// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

#define YES() cout << "YES\n"
#define NO() cout << "NO\n"

int main()
{
	ios_base::sync_with_stdio(false);

	int64_t t;
	cin >> t;
	while (t--)
	{
		int64_t a, b, c;
		cin >> a >> b >> c;

		if (a < b)
			swap(a, b);
		if (a < c)
			swap(a, c);
		if (b < c)
			swap(b, c);

		if (a == 4 * b && a == 4 * c)
			YES();
		else if (2 * a == 3 * b && 2 * a == 6 * c)
			YES();
		else if (a == b && a == c)
			YES();
		else if (a == 2 * b && a == 2 * c)
			YES();
		else if (a == 3 * b && a == 3 * c)
			YES();
		else if (a == b && a == 2 * c)
			YES();
		else
			NO();
	}

	return (0 ^ 0);
}