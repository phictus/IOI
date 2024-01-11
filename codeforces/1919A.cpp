// Parsa Jokar 2023 https://github.com/phictus/ioi

#pragma GCC optimize("Ofast")

#include <iostream>
#include <cstdint>

using namespace std;

void SolveTestCase()
{
    int64_t a, b;
    cin >> a >> b;
    if ((a + b) % 2 == 0)
        cout << "Bob\n";
    else
        cout << "Alice\n";
}

int main()
{
    ios_base::sync_with_stdio(false);

    int64_t testCase;
    cin >> testCase;
    while (testCase--)
        SolveTestCase();

    return (0 ^ 0);
}
