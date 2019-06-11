#include <iostream>
using namespace std;

int ** create_2darray(size_t a, size_t b) {
  int ** n = new int * [a];
  n[0] = new int [a * b];
  for (size_t i = 1; i != a; i++) {
    n[i] = n[i - 1] + b;
  }

  return n;
}

void swap_min(
  int * m[],
  unsigned rows,
  unsigned cols
) {
  unsigned min_row_index = 0;
  unsigned min_col_index = 0;

  for (unsigned i = 0; i != rows; i++) {
    for (unsigned j = 0; j != cols; j++) {
      if (m[i][j] < m[min_row_index][min_col_index]) {
        min_row_index = i;
        min_col_index = j;
      }
    }
  }

  int * tmp = m[0];
  m[0] = m[min_row_index];
  m[min_row_index] = tmp;
}

void print_matrix(
  int *m[ ],
  const unsigned rows,
  const unsigned cols
) {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << m[ i ][ j ] << ' ';
      std::cout << "\n";
    }
  }
}

void input_matrix(
  int * m[ ],
  const unsigned rows,
  const unsigned cols
) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      std::cout << "Input matrix[" << i << "," << j << "]: ";
      std::cin >> m[ i ][ j ];
    }
  }
}

int main() {
    unsigned rows, columns;
    std::cout << "Input number of rows: ";
    std::cin >> rows;
    std::cout << "Input number of columns: ";
    std::cin >> columns;
    int** matrix = new int*[ rows ];
    for ( size_t count = 0; count < rows; count++ )
        matrix[count] = new int[ columns ];
    input_matrix( matrix, rows, columns );
    std::cout << "\nYour matrix is... \n\n";
    print_matrix( matrix, rows, columns);
    std::cout << "\nChange row with first row ... \n\n";
    swap_min( matrix, rows, columns );
    std::cout << "Modified matrix... \n\n";
    print_matrix( matrix, rows, columns);
    std::cout << "\nFree memory... \n";
    for ( size_t count = 0; count < rows; count++ )
        delete[ ] matrix[ count ];
    return 0;
}
