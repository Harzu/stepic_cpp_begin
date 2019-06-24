#include <cstddef>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Array
{
public:
    explicit Array(size_t size = 0, const T & value = T())
        : size_(size)
        , data_(new T[size])
    {
        if (size != 0)
        {
            for (size_t i = 0; i < size; i++)
            {
                T v(value);
                data_[i] = v;
            }
        }
    };

    Array(const Array & other)
        : size_(other.size_)
        , data_(new T[other.size_])
    {
        for (size_t i = 0; i < other.size(); i++)
        {
            data_[i] = other.data_[i];
        }
    };

    ~Array()
    {
        delete [] data_;
        data_ = nullptr;
    };

    Array & operator = (const Array & other)
    {
        if (this != &other) Array<T>(other).swap(*this);
        return *this;
    };

    void swap(Array & other)
    {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }

    size_t size() const { return size_; };
    T & operator [] (size_t index) { return data_[index]; }
    const T & operator [] (size_t index) const { return data_[index]; }
private:
    size_t size_;
    T * data_;
};


int main() {
  Array<int> empty;
  Array<int> a(10, 0);
  Array<int> b(a);
  Array<int> c = b;
  
  std::cout << a.size() << std::endl;
  for (int i = 0; i < a.size(); i++) {
      std::cout << i << " " << a[i] << std::endl;
  }

  std::cout << b.size() << std::endl;
  for (int i = 0; i < b.size(); i++) {
      std::cout << i << " " << b[i] << std::endl;
  }

  std::cout << c.size() << std::endl;
  for (int i = 0; i < c.size(); i++) {
      std::cout << i << " " << c[i] << std::endl;
  }

  return 42;
}