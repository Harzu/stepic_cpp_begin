#include <iostream>
using namespace std;

int ** create_2darray(size_t a, size_t b)
{
    int ** n = new int * [a];
    n[0] = new int [a * b];
    for (size_t i = 1; i != a; i++)
    {
        n[i] = n[i - 1] + b;
    }

    return n;
}

int ** transpose(
  const int * const * m,
  unsigned rows,
  unsigned cols
) {
    int ** n = create_2darray(cols, rows);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            n[j][i] = m[i][j];
        }
    }

    return n;
};

int main() {
    int ** test = create_2darray(2, 4);
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            test[i][j] = j + 1;
        }
    }


    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            cout << test[i][j] << endl;
        }
    }

    int ** tr_array = transpose(test, 2, 4);

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            cout << tr_array[i][j] << endl;
        }
    }
    
    return 42;
}
