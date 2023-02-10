// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <set>

using namespace std;

int main()
{
    uint32_t n;
    cin >> n;
    set<uint64_t> x;
    for (size_t i = 0; i < n; i++)
    {
        uint64_t y;
        cin >> y;
        x.insert(y);
    }

    while(true)
    {

        uint64_t y = *x.rbegin();
        uint32_t z = y;
        while (y > 0 && x.count(y) > 0)
            y /= 2;
        if (y > 0)
        {
            x.erase(z);
            x.insert(y);
        }
        else
            break;
    }

    for (uint64_t e : x)
        cout << e << ' ';
    cout << endl;

    return (0 ^ 0);
}
