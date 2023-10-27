// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;
using Pair = pair<int64_t, int64_t>;

constexpr int64_t maxn = 300000;
int64_t n, m, winner;

class SegmentTree
{
public:
    SegmentTree()
    {
        m_data = new Pair[4 * maxn];
        for (int64_t i = 1; i < 4 * maxn; i++)
            m_data[i] = make_pair(-1, 0);
    }

    ~SegmentTree()
    {
        delete[] m_data;
    }

    void Update(int64_t begin, int64_t end, int64_t id = 1, int64_t l = 1, int64_t r = n + 1)
    {
        if (begin == end)
            return;

        if (l == begin && r == end)
        {
            if (m_data[id].first == -1)
                m_data[id] = make_pair(m, winner);
        }
        else
        {
            int64_t mid = (l + r) / 2;
            if (begin < mid)
                Update(begin, min(mid, end), 2 * id, l, mid);
            if (end >= mid)
                Update(max(mid, begin), end, 2 * id + 1, mid, r);
        }
    }

    Pair Query(int64_t index, int64_t id = 1, int64_t l = 1, int64_t r = n + 1)
    {
        if (l + 1 == r)
            return m_data[id];

        int64_t mid = (l + r) / 2;
        if (index < mid)
            return max(m_data[id], Query(index, 2 * id, l, mid));
        else
            return max(m_data[id], Query(index, 2 * id + 1, mid, r));
    }

private:
    Pair* m_data;
};

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    SegmentTree st;
    while (m--)
    {
        int64_t l, r;
        cin >> l >> r >> winner;
        st.Update(l, winner);
        st.Update(winner + 1, r + 1);
    }

    for (int64_t i = 1; i <= n; i++)
        cout << st.Query(i).second << '\n';

    return (0 ^ 0);
}
