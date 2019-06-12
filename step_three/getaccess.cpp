#include <iostream>
using namespace std;

struct Cls {
    Cls(char c = 's', double d = 1.0, int i = 1);
private:
    char c;
    double d;
    int i;
};

struct BCls {
  char c;
  double d;
  int i;
};

char & get_c(Cls &cls) {
  return ((BCls *) (& cls))->c;
}

double & get_d(Cls &cls) {
  return ((BCls *) (& cls))->d;
}

int & get_i(Cls &cls) {
  return ((BCls *) (& cls))->i;
}

int main() {
  return 42;
}