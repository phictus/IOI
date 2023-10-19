// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdint>

using namespace std;

struct Rect
{
	int64_t x, y, value;

	bool operator<(Rect& other)
	{
		return x < other.x;
	}
};

struct LinearFn
{
	int64_t m, c;

	int64_t operator()(int64_t x)
	{
		return m * x + c;
	}

	int64_t GetIntersectX(const LinearFn& other)
	{
		return (c - other.c) / (other.m - m);
	}
};

constexpr int64_t maxn = 1000000;
int64_t n;
Rect rects[maxn];
deque<LinearFn> fnList;
int64_t dp[maxn];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int64_t i = 0; i < n; i++)
		cin >> rects[i].x >> rects[i].y >> rects[i].value;
	sort(rects, rects + n);

	fnList.push_back({ 0, 0 });
	for (int64_t i = 0; i < n; i++)
	{
		while (fnList.size() >= 2 && fnList.back()(rects[i].y) <= fnList[fnList.size() - 2](rects[i].y))
			fnList.pop_back();

		dp[i] = fnList.back()(rects[i].y) + rects[i].x * rects[i].y - rects[i].value;

		LinearFn newFn = { -rects[i].x, dp[i] };
		while (fnList.size() >= 2 && newFn.GetIntersectX(fnList[0]) >= fnList[0].GetIntersectX(fnList[1]))
			fnList.pop_front();
		fnList.push_front(newFn);
	}

	cout << *max_element(dp, dp + n) << '\n';

	return (0 ^ 0);
}