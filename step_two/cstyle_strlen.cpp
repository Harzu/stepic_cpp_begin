#include <iostream>
using namespace std;

unsigned str_len(const char *str) {
  unsigned counter = 0;
  for (; *str != '\0'; str++) {
    counter++;
  }
  return counter;
}

int main() {
  char text[] = "hassllsssss";
  cout << str_len(text) << endl;
  return 42;
}