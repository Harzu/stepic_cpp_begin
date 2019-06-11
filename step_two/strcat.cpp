#include <iostream>
using namespace std;

void stringcat(char *to, const char *from) {  
  if (*to != '\0') { // check non empty first char buffer
    while(*++to); // go to end first char buffer
  }
  
  // add next after end first char buffer
  // char from second char buffer
  while (*to++ = *from++);
  // add end char in char buffer
  *to = '\0';
}

int main() {
  char to[] = "Hello ";
  const char from[] = "World";

  stringcat(to, from);
  cout << to << endl;
  return 42;
}