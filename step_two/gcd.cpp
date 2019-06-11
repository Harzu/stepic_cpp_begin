#include <iostream>
using namespace std;

unsigned gcd(unsigned a, unsigned b) {
    if (a == 0) return b;
    if (b == 0) return a;
    
    if (a >= b) {
        return gcd(a % b, b);
    } else {
      return gcd(a, b % a);
    }
}

int main() {
  cout << gcd(2, 2) << endl;
  return 0;
}