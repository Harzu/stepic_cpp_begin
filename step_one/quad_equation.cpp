#include <math.h>
#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int d = (b * b) - (4 * a * c);
    if (d >= 0)
    {
        double x1 = ((0 - b) + sqrt(d)) / (2 * a);
        double x2 = ((0 - b) - sqrt(d)) / (2 * a);
        cout << x1 << " " << x2 << endl;
    }
    else if (d < 0)
    {
        cout << "No real roots" << endl;
    }

    return 0;
}