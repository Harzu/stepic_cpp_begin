#include <iostream>
using namespace std;

char * resize(const char *str, unsigned size, unsigned new_size) {
  char * new_str = new char[new_size];
  for (int i = 0; i < new_size; i++) new_str[i] = str[i];

  delete[] str;
  str = 0;
  return new_str;
}

char * getline() {
  unsigned size = 0;
  unsigned index = 0;
  
  char c = '\0';
  char * str = new char[size];
  
  while (std::cin.get(c) && c != '\n') {
    str = resize(str, size, size + 1);
    size++;
    str[index++] = c;
  }

  str[index] = '\0';
  return str;
}

int main() {
  return 42;
}