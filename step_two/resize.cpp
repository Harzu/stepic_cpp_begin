#include <iostream>
using namespace std;

char * resize(const char *str, unsigned size, unsigned new_size) {
  char * new_str = new char[new_size];
  for (int i = 0; i < new_size; i++) new_str[i] = str[i];

  delete[] str;
  str = 0;
  return new_str;
}

int main() {
  char * all = resize("str", 3, 2);
  cout << all << endl;
  delete[] all;
  all = 0;
  return 42;
}