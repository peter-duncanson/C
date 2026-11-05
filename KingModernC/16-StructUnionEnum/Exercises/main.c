#include <stdio.h>
#include "exercises.h"

int main(void)
{
    // 6
    // struct time ans = split_time((long)3661);
    // printf("hours: %d\nminutes: %d\nseconds: %d\n", ans.hours, ans.minutes, ans.seconds);
    
    // 7
    //
    struct fraction f;
    f.numerator = 6;
    f.denominator = 28;
    struct fraction r = reduce(f);
    printf("n = %d\nd = %d\n", r.numerator, r.denominator);

    return 0;
}
