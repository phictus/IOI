// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 3001;
string s,t;
int64_t dp[maxn][maxn];

void init()
{
	for (int64_t i = 0; i < s.size(); i++)
		dp[i][0] = 0;
	for (int64_t i = 1; i < t.size(); i++)
		dp[0][i] = 0;

	for (int64_t i = 1; i < s.size(); i++)
	{
		for (int64_t j = 1; j < t.size(); j++)
		{
			if (s[i] == t[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
}

string getLCS(int64_t i = s.size() - 1, int64_t j = t.size() - 1)
{
	if (i == 0 || j == 0)
		return "";

	if (s[i] == t[j])
		return getLCS(i - 1, j - 1) + s[i];
	else if (dp[i][j - 1] > dp[i - 1][j])
		return getLCS(i, j - 1);
	else
		return getLCS(i - 1, j);
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> s >> t;
	s = " " + s;
	t = " " + t;

	init();
	cout << getLCS() << '\n';

	return (0 ^ 0);
}