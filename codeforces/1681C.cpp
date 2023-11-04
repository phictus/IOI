// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 100;
int64_t n;
int64_t arr[2][maxn];
vector<Pair> swapList;

inline void Swap(int64_t x, int64_t y)
{
    swap(arr[0][x], arr[0][y]);
    swap(arr[1][x], arr[1][y]);
}

void Sort(int64_t type, int64_t l, int64_t r)
{
    if (l + 1 == r)
        return;

    int64_t maximum = l;
    for (int64_t i = l + 1; i < r; i++)
    {
        if (arr[type][maximum] < arr[type][i])
            maximum = i;
    }

    if (maximum != r - 1)
    {
        swapList.push_back(make_pair(maximum + 1, r));
        Swap(maximum, r - 1);
    }

    Sort(type, l, r - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int64_t i = 0; i < n; i++)
            cin >> arr[0][i];
        for (int64_t i = 0; i < n; i++)
            cin >> arr[1][i];

        Sort(0, 0, n);
        int64_t last = 0;
        for (int64_t i = 1; i < n; i++)
        {
            if (arr[0][i] != arr[0][i - 1])
            {
                Sort(1, last, i);
                last = i;
            }
        }
        Sort(1, last, n);

        bool isPossible = true;
        for (int64_t i = 1; i < n; i++)
        {
            if (arr[1][i] < arr[1][i - 1])
                isPossible = false;
        }

        if (isPossible)
        {
            cout << swapList.size() << '\n';
            for (Pair& e : swapList)
                cout << e.first << ' ' << e.second << '\n';
        }
        else
            cout << "-1\n";

        swapList.clear();
    }

    return (0 ^ 0);
}
