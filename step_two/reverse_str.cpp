#include <iostream>
using namespace std;

void reverse_str()
{
    char x [10];
    cin >> x;
    if (x[0] != '0')
    {
        reverse_str();
        cout << x << ' ';
    }
}

int main()
{
    reverse_str();
    return 0;
}