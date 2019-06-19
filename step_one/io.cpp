#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int x;
    int y;
    scanf("%d", &y);
    printf("output value with stdio.h %d\n", y);
  
    cout << "input x" << "\n";
    cin >> x;
    cout << "output x: " << x << "\n";

    char c = '\0';
    while (cin.get(c))
    {
        cout << c << endl;
    }
    return 42;
}