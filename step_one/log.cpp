#include <iostream>
using namespace std;

int log(int i) {
  int answer = -1;
  while (i > 0) {
      i >>= 1;
      answer++;
  }
    
  return answer;
}

int main() {
  int count;
  cin >> count;

  for (int i = 0; i < count; i++) {
    int x;
    cin >> x;
    cout << log(x) << endl;
  }
}