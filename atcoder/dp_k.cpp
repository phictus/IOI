// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 100, maxk = 100001;
int64_t n, k, a[maxn];
bool dp[maxk];

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    for (int64_t i = 0; i < a[0]; i++)
        dp[i] = false;
    for (int64_t i = a[0]; i <= k; i++)
    {
        dp[i] = false;
        for (int64_t j = 0; j < n && a[j] <= i; j++)
        {
            if (!dp[i - a[j]])
            {
                dp[i] = true;
                break;
            }
        }
    }

    if (dp[k])
        cout << "First\n";
    else
        cout << "Second\n";

    return (0 ^ 0);
}
