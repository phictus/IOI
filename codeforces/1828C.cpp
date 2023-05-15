// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <algorithm>

using namespace std;

constexpr int64_t mod = 1000000007;

int64_t numberOfChoicesCache = 0;
int64_t numberOfChoices(int64_t number, int64_t size, int64_t* array)
{
    int64_t result = 0;
    for (int64_t i = numberOfChoicesCache; i < size; i++)
    {
        if (number > array[i])
            result++;
        else
            break;
    }

    numberOfChoicesCache += result;
    return numberOfChoicesCache;
}

int main()
{
    int64_t t;
    cin >> t;
    while (t--)
    {
        int64_t n;
        cin >> n;
        int64_t a[n];
        int64_t b[n];
        for (int64_t i = 0; i < n; i++)
            cin >> a[i];
        for (int64_t i = 0; i < n; i++)
            cin >> b[i];

        sort(a, a + n);
        sort(b, b + n);

        int64_t result = 1;
        for (int64_t i = 0; i < n; i++)
            result = (result * (numberOfChoices(a[i], n, b) - i)) % mod;

        cout << result << endl;
        numberOfChoicesCache = 0;
    }

    return (0 ^ 0);
}
