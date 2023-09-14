#include <iostream>
#include <map>

using namespace std;

int64_t n;
string a;
map<int64_t, int64_t> m;

inline constexpr int64_t toInt(char v)
{
    return (int64_t)(v - '0');
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t q;
    cin >> q;
    while (q--)
    {
        m.clear();
        m[0] = 1;

        cin >> n;
        cin >> a;

        int64_t result = 0, sum = 0;
        for (int64_t i = 0; i < n; i++)
        {
            sum += toInt(a[i]);
            result += m[sum - i - 1];
            m[sum - i - 1]++;
        }

        cout << result << '\n';
    }
}
