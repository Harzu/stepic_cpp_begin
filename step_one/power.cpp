#include <stdio.h>

int power(int x, unsigned p)
{
    int answer = 1;
    while (p--) answer *= x;
    return answer;
}

int main()
{
    printf("%d", power(0, 0));
    return 0;
}