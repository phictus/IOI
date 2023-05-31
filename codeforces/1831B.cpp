// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <set>
#include <cstring>

using namespace std;

void input(int64_t n, int64_t* array, int64_t* data, set<int64_t>& usedNumbers)
{
    int64_t x = 1;
    for (int64_t i = 0; i < n; i++)
    {
        cin >> array[i];
        usedNumbers.insert(array[i]);

        if (i != 0 && array[i - 1] == array[i])
            x++;
        else
            x = 1;

        data[array[i]] = max(data[array[i]], x);
    }
}

int main()
{
    int64_t t;
    cin >> t;
    while (t--)
    {
        int64_t n;
        cin >> n;
        int64_t a[n], b[n];
        int64_t aData[2 * n + 1], bData[2 * n + 1];
        memset(aData, 0, (2 * n + 1) * sizeof(int64_t));
        memset(bData, 0, (2 * n + 1) * sizeof(int64_t));

        set<int64_t> usedNumbers;
        input(n, a, aData, usedNumbers);
        input(n, b, bData, usedNumbers);

        int64_t result = 0;
        for (int64_t number : usedNumbers)
            result = max(result, aData[number] + bData[number]);
        cout << result << endl;
    }

    return (0 ^ 0);
}
