#include <iostream>

using namespace std;

#define MAX(x, y, r) \
{ \
    int arg1 = x; \
    int arg2 = y; \
    r = arg1 > arg2 ? arg1 : arg2; \
}

int main()
{
    int a = 10;
    int b = 20;
    int c = 0;
    MAX(a, b, c);
    MAX(a += b, b, c);
    cout << c << endl;
    return 0;
}