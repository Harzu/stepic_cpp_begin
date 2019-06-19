#include "../step_four/expression.cpp"
using namespace std;

struct Counter 
{
public:
    void increment() { count_++; }
    size_t decrement() { return --count_; }
private:
    size_t count_;
};

struct SharedPtr
{
    explicit SharedPtr(Expression * ptr = 0)
      : counter(0), pointer(ptr)
    {
        if (pointer != 0)
        {
            counter = new Counter();
            counter->increment();
        }
    };
    
    ~SharedPtr()
    {
        if (pointer != 0)
        {
            if (counter->decrement() == 0)
            {
                delete counter;
                delete pointer;
            }
        }
    };

    SharedPtr(const SharedPtr & other)
      : counter(other.counter), pointer(other.pointer)
    {
        if (pointer != 0)
        {
            counter->increment();
        }
    };

    SharedPtr & operator = (const SharedPtr & other)
    {
        if (this != &other)
        {
            if (pointer != 0)
            {
                if (counter->decrement() == 0)
                {
                    delete counter;
                    delete pointer;
                }
            }

            if (other.pointer != 0)
            {
                pointer = other.pointer;
                counter = other.counter;
                counter->increment();
            }
        }

        return *this;
    };
    
    void reset(Expression * ptr = 0)
    {
      if (pointer)
      {
        if (counter->decrement() == 0)
        {
          delete pointer;
          delete counter;
        }
      }
      
      pointer = ptr;
      counter = 0;
      if (pointer != 0)
      {
        counter = new Counter();
        counter->increment();
      }
    };
    
    Expression * get() const { return pointer; };
    Expression & operator * () const { return * pointer; };
    Expression * operator -> () const { return pointer; };
private:
    Counter * counter;
    Expression * pointer;
};