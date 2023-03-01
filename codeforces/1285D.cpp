// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <vector>

using namespace std;

int32_t solve(vector<uint32_t> values, int32_t index)
{
    if (index < 0)
        return 0;

    vector<uint32_t> zero, one;
    for (uint32_t value : values)
    {
        if ((1 << index & value) == 0)
            zero.push_back(value);
        else
            one.push_back(value);
    }

    if (zero.size() == 0)
        return solve(one, index - 1);
    if (one.size() == 0)
        return solve(zero, index - 1);

    return (1 << index) + min(solve(zero, index - 1), solve(one, index - 1));
}

int main()
{
    uint32_t n;
    cin >> n;
    vector<uint32_t> values;
    for (uint32_t i = 0; i < n; i++)
    {
        uint32_t value;
        cin >> value;
        values.push_back(value);
    }

    cout << solve(values, 30) << endl;

    return (0 ^ 0);
}
