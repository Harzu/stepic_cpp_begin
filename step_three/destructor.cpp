#include <iostream>
#include <cstddef> // size_t
#include <cstring> // strlen, strcpy

struct String {
	String(size_t n, char c) {
    size = n;
    str = new char[size + 1];
    if (size > 0) {
      for (size_t i = 0; i < size; i++) str[i] = c;
    }
    str[size] = '\0';
  };

	~String() {
    delete [] str;
    str = 0;
  };

	size_t size;
	char * str;
};

int main() {
  String hello(0, 'j');
  std::cout << "string: " << hello.str << std::endl;
  return 42;
}