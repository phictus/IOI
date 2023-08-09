// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <cstdint>

using namespace std;

constexpr uint64_t maxn = 200001;
uint64_t n, m;
uint64_t capacity[maxn];
uint64_t initialCapacity[maxn];
uint64_t parent[maxn];

uint64_t FindSetParent(uint64_t v)
{
    if (parent[v] == v)
        return v;

    return parent[v] = FindSetParent(parent[v]);
}

void PourWater(uint64_t vessel, uint64_t litre)
{
    vessel = FindSetParent(vessel);

    if (capacity[vessel] > litre)
    {
        capacity[vessel] -= litre;
        return;
    }

    if (vessel == n)
    {
        capacity[vessel] = 0;
        return;
    }

    parent[vessel] = vessel + 1;
    PourWater(vessel, litre - capacity[vessel]);
    capacity[vessel] = 0;
}

int main()
{
    cin >> n;
    for (uint64_t i = 1; i <= n; i++)
    {
        cin >> capacity[i];
        initialCapacity[i] = capacity[i];
        parent[i] = i;
    }

    cin >> m;
    while (m--)
    {
        uint64_t o, vessel, litre;
        cin >> o >> vessel;
        if (o == 1)
        {
            cin >> litre;
            PourWater(vessel, litre);
        }
        else
            cout << initialCapacity[vessel] - capacity[vessel] << endl;
    }

    return (0 ^ 0);
}
