#include <iostream>
        
struct Foo {
  void say() const { std::cout << "Foo says: " << msg << "\n"; }
protected:
  Foo(const char *msg) : msg(msg) { }
private:
  const char *msg;
};

struct Bar : Foo {
    Bar(const char *msg)
        : Foo(msg)
    {};
};

Foo get_foo(const char *msg) {
  return Bar(msg);
}

int main() {
  return 42;
}