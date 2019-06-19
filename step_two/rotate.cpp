#include <iostream>
using namespace std;

void swap(int a[], unsigned fi, unsigned si)
{
    int tmp = a[fi];
    a[fi] = a[si];
    a[si] = tmp;
}

void rotate(int a[], unsigned size, int shift)
{
    if (shift < 0) shift = -shift;
    shift %= size;
    
    if (shift > 0 && size > 0)
    {
        for (int i = 0; i < shift; i++)
        {
            for (int j = 0; j < size && j + 1 < size; j++) swap(a, j, j + 1);
        }
    }
}

int main()
{
    int test[5] = { 1, 2, 3, 4, 5 };
    int length = (sizeof(test)/sizeof(*test));
    
    rotate(test, length, 2);
    for (int i = 0; i < length; i++)
    {
        cout << test[i] << endl;
    }
    
    return 0;
}