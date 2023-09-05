// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr uint32_t maxn = 500000, maxsqrtn = 500;
uint32_t n, q;
uint64_t arr[maxn];
vector<uint64_t> dp[maxn / maxsqrtn];

void update(uint32_t index, uint64_t value)
{
    const uint32_t block = index / maxsqrtn;

    uint32_t l = 0, r = dp[block].size() - 1, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (dp[block][m] < arr[index])
            l = m + 1;
        else if (dp[block][m] > arr[index])
            r = m - 1;
        else
        {
            dp[block][m] = value;
            arr[index] = value;
            sort(dp[block].begin(), dp[block].end());
            return;
        }
    }

}

uint32_t get(uint32_t left, uint32_t right, uint64_t value)
{
    uint32_t result = 0;
    uint32_t leftBlock = left / maxsqrtn;
    uint32_t rightBlock = right / maxsqrtn;

    if (leftBlock == rightBlock)
    {
        for (uint32_t i = left; i <= right; i++)
            if (arr[i] >= value)
                result++;
    }
    else
    {
        if (left % maxsqrtn != 0)
            leftBlock++;
        if ((right + 1) % maxsqrtn == 0)
            rightBlock++;
        for (uint32_t i = leftBlock; i < rightBlock; i++)
            result += dp[i].end() - lower_bound(dp[i].begin(), dp[i].end(), value);

        for (uint32_t i = left; i < leftBlock * maxsqrtn; i++)
            if (arr[i] >= value)
                result++;
        for (uint32_t i = rightBlock * maxsqrtn; i <= right; i++)
            if (arr[i] >= value)
                result++;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (uint32_t i = 0; i < n; i++)
        cin >> arr[i];

    for (uint32_t i = 0; i < n; i++)
        dp[i / maxsqrtn].push_back(arr[i]);
    for (uint32_t i = 0; i <= (n - 1) / maxsqrtn; i++)
        sort(dp[i].begin(), dp[i].end());

    cin >> q;
    while (q--)
    {
        uint32_t option, a, b, c;
        cin >> option;
        if (option == 0)
        {
            cin >> a >> b >> c;
            cout << get(a - 1, b - 1, c) << '\n';
        }
        else
        {
            cin >> a >> b;
            update(a - 1, b);
        }
    }

    return (0 ^ 0);
}
