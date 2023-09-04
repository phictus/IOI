// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Print(const vector<uint64_t>& vec)
{
    cout << vec.size();
    for (uint64_t e : vec)
        cout << ' ' << e;
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);

    uint64_t n, k;
    cin >> n >> k;
    uint64_t a[n];
    for (uint64_t i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    vector<uint64_t> result;
    for (uint64_t i = 1; i <= n; i++)
    {
        for (uint64_t j = 0; j <= n - i; j++)
        {
            result.push_back(a[j]);
            Print(result);
            result.pop_back();

            k--;
            if (k == 0)
                return 0;
        }
        result.push_back(a[n - i]);
    }

    return (0 ^ 0);
}
