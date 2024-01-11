// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;
constexpr int64_t mod = 1000000007;

struct Mat3
{
    Mat3()
    {
        for (int64_t i = 0; i < 3 * 3; i++)
            data[i] = 0;
    }

    int64_t& Get(int64_t i, int64_t j)
    {
        return data[3 * i + j];
    }

    int64_t Get(int64_t i, int64_t j) const
    {
        return data[3 * i + j];
    }

    Mat3 Mul(const Mat3& other)
    {
        Mat3 result;
        for (int64_t i = 0; i < 3; i++)
        {
            for (int64_t j = 0; j < 3; j++)
            {
                for (int64_t k = 0; k < 3; k++)
                {
                    result.Get(i, j) += Get(i, k) * other.Get(k, j);
                    result.Get(i, j) %= mod;
                }
            }
        }

        return result;
    }

    Mat3 Pow(int64_t power)
    {
        if (power == 1)
            return *this;
        if (power == 2)
            return this->Mul(*this);

        Mat3 result = this->Pow(power / 2);
        result = result.Mul(result);
        if (power % 2 == 1)
            result = result.Mul(*this);

        return result;
    }

    int64_t data[3 * 3];
};

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t n;
    cin >> n;

    Mat3 base;
    base.Get(0, 0) = 1;
    base.Get(0, 1) = 1;
    base.Get(1, 2) = 1;
    base.Get(2, 0) = 1;

    cout << base.Pow(n + 2).Get(0, 0) << '\n';

    return (0 ^ 0);
}
