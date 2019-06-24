struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

template <typename T>
struct ValueHolder : public ICloneable
{
public:
    T data_;
    ValueHolder(const T & value) : data_(T(value)) {};
    ~ValueHolder() {};
    ValueHolder * clone() const { return new ValueHolder<T>(*this); };
};

int main()
{
    ICloneable * first = new ValueHolder<int>(1313);
    return 42;
}