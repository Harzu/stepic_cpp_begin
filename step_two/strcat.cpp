#include <iostream>
using namespace std;

void stringcat(char *to, const char *from)
{
    if (*to != '\0')
    {
        while(*++to);
    }
  
    while (*to++ = *from++);
    *to = '\0';
}

int main()
{
    char to[] = "Hello ";
    const char from[] = "World";

    stringcat(to, from);
    cout << to << endl;
    return 42;
}