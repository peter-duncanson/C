#include <stdio.h>
#include <stdbool.h>

bool is_square(int n)
{
    if (n < 0) return false;
    if (n <= 1) return true;

    int left = 1, right = n;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        long long square = (long long)(mid * mid);
        
        if (square == n) return true;
        if (square < n) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

int main(void)
{
    int x = 45;

    if (is_square(x)) puts("true");
    else puts("false");

}
