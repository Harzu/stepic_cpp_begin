#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
  String(const char * str = "") {
    size = strlen(str);
    this->str = new char[size + 1];
    strcpy(this->str, str);
  };

  size_t size;
  char * str;
};

int main() {
  String hello("Hello");
  std::cout << hello.str << std::endl;
  return 42;
}