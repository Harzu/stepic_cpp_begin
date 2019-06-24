#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T& value = T());
    Array(const Array& other);
    ~Array();
    Array& operator=(Array other);
    void swap(Array &other);
    size_t size() const;
    T& operator[](size_t idx);
    const T& operator[](size_t idx) const;

private:
    size_t size_;
    T *data_;
};

template <class T, class Comp>
T minimum(Array<T> a, const Comp & c)
{
    if (a.size() != 0)
    {
        T res = a[0];
        for (size_t i = 0; i < a.size(); i++)
        {
            res = (!c(res, a[i])) ? a[i] : res;
        }

        return res;
    }
};