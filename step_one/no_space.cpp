#include <iostream>
using namespace std;

int main() {
  int count = 0;
  char c = '\0';
  while (cin.get(c)) {
    if (c == '\n') {
      break;
    } else if (c == ' ') {
      count++;
    } else {
      cout << c;
      count = 0;
    }
    
    if (count == 1) {
      cout << c;
    }
  }

	return 0;
}