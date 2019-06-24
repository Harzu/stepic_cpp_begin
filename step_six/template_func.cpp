#include <cstddef>
template <typename T, typename U>
void copy_n(T * a, U * b, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        a[i] = ((T)b[i]);
    }
}