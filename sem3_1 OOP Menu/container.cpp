
template <typename T>
class Container
{
private:
    int m_capacity;
    T *m_array;
    int m_count;

    inline void checkCanAdd() const
    {
        if (m_count >= m_capacity)
        {
            throw "Exceeded container's capacity";
        }
    }

    inline void checkIndexWithinBounds(int index) const
    {
        if (index < 0 || index >= m_count)
        {
            throw "Index out of range";
        }
    }

public:
    // https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html
    typedef T *iterator;
    typedef const T *const_iterator;
    iterator begin() const { return m_array; }
    iterator end() const { return m_array + m_count; }

    Container(int capacity) : m_capacity(capacity)
    {
        m_count = 0;
        m_array = new T[capacity];
    }

    ~Container()
    {
        delete[] m_array;
    }

    void add(const T &item)
    {
        checkCanAdd();
        m_array[m_count] = item;
        m_count++;
    }

    int count() const
    {
        return m_count;
    }

    T &operator[](int index)
    {
        checkIndexWithinBounds(index);
        return m_array[index];
    }

    void addAt(const T &item, iterator at)
    {
        checkCanAdd(); // throw if can't add any more items

        // take element at location `iter - 1` at put it into `iter`
        for (auto iter = end(); iter > at; iter--)
        {
            *iter = *(iter - 1);
        }

        *at = item;
        m_count++;
    }

    // https://stackoverflow.com/questions/32926042/how-to-implement-a-simple-container-with-placement-new-and-emplace-functionality
    // template <typename... Ts>
    // const T &emplace(Ts &&... args)
    // {
    //     checkCanAdd();
    //     *(m_array + m_count) = T(std::forward<Ts>(args)...));
    //     m_count++;
    //     return m_array + (m_count - 1);
    // }

    typedef int (*CompareFunc)(const T &, const T &);

    void sort(CompareFunc compareFunc)
    {
        // I'm going to do a dumb sort so as not to waste too much time
        for (auto i = begin(); i < end(); i++)
            for (auto j = begin(); j < end(); j++)
                if (compareFunc(*i, *j) > 0)
                {
                    T temp = *i;
                    *i = *j;
                    *j = temp;
                }
    }
};