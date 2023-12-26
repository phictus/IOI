// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#include <iostream>
#include <cstdint>

using namespace std;

constexpr int64_t mod = 1000000007;
int64_t n, m;

struct Matrix
{
    constexpr static int64_t max = 100;
    int64_t data[max * max];

    int64_t& Get(int64_t i, int64_t j)
    {
        return data[max * i + j];
    }

    const int64_t& Get(int64_t i, int64_t j) const
    {
        return data[max * i + j];
    }

    static Matrix GetZero()
    {
        Matrix result;
        for (int64_t i = 0; i < m; i++)
        {
            for (int64_t j = 0; j < m; j++)
                result.Get(i, j) = 0;
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const
    {
        Matrix result = GetZero();
        for (int64_t i = 0; i < m; i++)
        {
            for (int64_t j = 0; j < m; j++)
            {
                for (int64_t k = 0; k < m; k++)
                {
                    result.Get(i, j) += Get(i, k) * other.Get(k, j);
                    result.Get(i, j) %= mod;
                }
            }
        }

        return result;
    }

    Matrix Power(int64_t power)
    {
        if (power == 1)
            return *this;

        Matrix result = Power(power / 2);
        result = result * result;
        if (power % 2 == 1)
            result = result * *this;

        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    Matrix result = Matrix::GetZero();
    result.Get(0, 0) = 1;
    for (int64_t i = 1; i < m; i++)
        result.Get(i - 1, i) = 1;
    result.Get(m - 1, 0) = 1;
    cout << result.Power(n).Get(0, 0) << '\n';

    return (0 ^ 0);
}
