// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <cstdio>
#include <cstdint>

using namespace std;

int64_t Calculate(int64_t m, int64_t h, int64_t a, int64_t x, int64_t y) {
    for (int64_t i = 1; i <= m; i++)
    {
        h = ((h * x % m) + y) % m;
        if (h == a)
            return i;
    }

    return -1;
}

int32_t main(){
    int64_t m, h1, a1, x1, y1, h2, a2, x2, y2;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",
        &m,
        &h1, &a1, &x1, &y1,
        &h2, &a2, &x2, &y2
    );

    int64_t p1 = Calculate(m, h1, a1, x1, y1);
    int64_t c1 = Calculate(m, a1, a1, x1, y1);
    int64_t p2 = Calculate(m, h2, a2, x2, y2);
    int64_t c2 = Calculate(m, a2, a2, x2, y2);

    if (p1 == -1 || p2 == -1)
    {
        puts("-1");
        return 0;
    }

    for(int32_t i = 0; i <= 2 * m; i++)
    {
        if (p1 == p2)
        {
            printf("%lld\n", p1);
            return 0;
        }
        if (p1 < p2)
        {
            if (c1 == -1)
                puts("-1");
            p1 += c1;
        }
        else
        {
            if (c1 == -1)
            {
                puts("-1");
                return 0;
            }

            p2 += c2;
        }
    }

    puts("-1");

    return (0 ^ 0);
}
