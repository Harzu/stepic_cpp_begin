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

template <typename T>
void flatten(const Array<T> & src, std::ostream & out)
{
    for (size_t i = 0; i < src.size(); i++)
    {
        out << src[i] << " ";
    }
}

template <typename T>
void flatten(const Array<Array<T>> & src, std::ostream & out)
{
    for (size_t i = 0; i < src.size(); i++)
    {
        flatten(src[i], out);
    }
}