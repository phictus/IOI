// Parsa Jokar 2023 https://github.com/phictus/ioi

#include <iostream>
#include <limits>
#include <cstdint>

using namespace std;

constexpr int64_t maxn = 200000, inf = numeric_limits<int64_t>::max();
int64_t n, m, a[maxn];

struct SegmentTree
{
public:
    SegmentTree()
    {
        m_data = new int64_t[4 * n];
        m_lazy = new int64_t[4 * n];

        InitData();
        for (int64_t i = 1; i < 4 * n; i++)
            m_lazy[i] = 0;
    }

    ~SegmentTree()
    {
        delete[] m_data;
        delete[] m_lazy;
    }

    void Update(int64_t begin, int64_t end, int64_t value, int64_t id = 1, int64_t l = 0, int64_t r = n)
    {
        if (begin >= r || end <= l)
            return;
        if (begin <= l && end >= r)
        {
            m_data[id] += value;
            m_lazy[id] += value;
            return;
        }

        SpreadLazy(id);

        int64_t mid = (l + r) / 2;
        Update(begin, min(mid, end), value, 2 * id, l, mid);
        Update(max(mid, begin), end, value, 2 * id + 1, mid, r);
        m_data[id] = min(m_data[2 * id], m_data[2 * id + 1]);
    }

    int64_t Query(int64_t begin, int64_t end, int64_t id = 1, int64_t l = 0, int64_t r = n)
    {
        if (begin >= r || end <= l)
            return inf;
        if (begin <= l && end >= r)
            return m_data[id];

        SpreadLazy(id);

        int64_t mid = (l + r) / 2;
        return min(Query(begin, min(mid, end), 2 * id, l, mid), Query(max(mid, begin), end, 2 * id + 1, mid, r));
    }

public:
    void InitData(int64_t id = 1, int64_t l = 0, int64_t r = n)
    {
        if (l + 1 == r)
            m_data[id] = a[l];
        else
        {
            int64_t mid = (l + r) / 2;
            InitData(2 * id, l, mid);
            InitData(2 * id + 1, mid, r);

            m_data[id] = min(m_data[2 * id], m_data[2 * id + 1]);
        }
    }

    void SpreadLazy(int64_t id)
    {
        m_lazy[2 * id] += m_lazy[id];
        m_lazy[2 * id + 1] += m_lazy[id];

        m_data[2 * id] += m_lazy[id];
        m_data[2 * id + 1] += m_lazy[id];

        m_lazy[id] = 0;
    }

    int64_t* m_data;
    int64_t* m_lazy;
};

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int64_t i = 0; i < n; i++)
        cin >> a[i];

    SegmentTree st;

    cin >> m;
    while (m--)
    {
        int64_t l, r;
        cin >> l >> r;
        if (cin.peek() != '\n')
        {
            int64_t value;
            cin >> value;
            if (l <= r)
                st.Update(l, r + 1, value);
            else
            {
                st.Update(0, r + 1, value);
                st.Update(l, n, value);
            }
        }
        else
        {
            if (l <= r)
                cout << st.Query(l, r + 1) << '\n';
            else
                cout << min(st.Query(0, r + 1), st.Query(l, n)) << '\n';
        }
    }

    return (0 ^ 0);
}
