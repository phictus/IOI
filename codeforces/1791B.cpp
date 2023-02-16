// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <string>

using namespace std;

int main()
{
    uint32_t t;
    cin >> t;
    while (t--)
    {
        uint32_t n;
        cin >> n;
        string s;
        cin >> s;

        int32_t x = 0, y = 0;
        for (char e : s)
        {
            switch (e)
            {
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                case 'R':
                    x++;
                    break;
                case 'L':
                    x--;
                    break;
            }

            if (x == 1 && y == 1)
                goto LABEL0;
        }

        cout << "NO" << endl;
        continue;
    LABEL0:
        cout << "YES" << endl;
    }

    return (0 ^ 0);
}
