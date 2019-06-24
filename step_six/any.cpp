#include <algorithm>

struct ICloneable;

template <typename T>
struct ValueHolder;

class Any
{
public:
    Any() : data_(nullptr) {};
    
    template <typename O>
    explicit Any(const O & value) : data_(new ValueHolder<O>(value)) {};
        
     ~Any() { delete data_; }
    Any(const Any & other)
        : data_(other.data_ ? other.data_->clone() : nullptr)
    {};

    Any & operator = (const Any & other)
    {
        if (this != &other) Any(other).swap(*this);
        return *this;
    }
    
    template <typename T>
    Any & operator = (const T & other)
    {
        Any tmp(other);
        Any * ptr = & tmp;
        if (this != ptr) Any(other).swap(*this);
        return *this;
    }
    
    void swap(Any & other) { std::swap(data_, other.data_); }
    
    template <typename A>
    A * cast() const
    {
        ValueHolder<A> * data = dynamic_cast<ValueHolder<A> *>(data_);
        if (data == nullptr || !this->data_)
        {
            return nullptr;
        }
        
        return &(data->data_);
    }
private:
    ICloneable * data_;
};