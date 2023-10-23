// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

constexpr int64_t inf = numeric_limits<int64_t>::max();

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        int64_t n, k;
        cin >> n >> k;

        if (k == 4)
        {
            int64_t mul = 1;
            bool isThree = false;
            for (int64_t i = 0; i < n; i++)
            {
                int64_t a;
                cin >> a;

                mul *= a;
                mul %= k;

                if (a % k == 3)
                    isThree = true;
            }

            if (mul == 0)
                cout << "0\n";
            else if (mul == 2)
                cout << "1\n";
            else if (isThree)
                cout << "1\n";
            else
                cout << "2\n";
        }
        else
        {
            int64_t result = inf;
            for (int64_t i = 0; i < n; i++)
            {
                int64_t a;
                cin >> a;
                if (a % k == 0)
                    result = 0;
                else
                    result = min(result, k - (a % k));
            }

            cout << result << '\n';
        }
    }

    return (0 ^ 0);
}
