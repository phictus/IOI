// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        int64_t n, x;
        cin >> n >> x;

        int64_t degree = 0;
        for (int64_t i = 1; i < n; i++)
        {
            int64_t v, u;
            cin >> v >> u;
            if (v == x || u == x)
                degree++;
        }

        if (degree <= 1 || n % 2 == 0)
            cout << "Ayush\n";
        else
            cout << "Ashish\n";
    }

    return (0 ^ 0);
}
