// 6
struct time {
    int hours;
    int minutes;
    int seconds;
};
struct time split_time(long total_seconds);

// 7
struct fraction {
    int numerator;
    int denominator;
};
struct fraction reduce(struct fraction a);
struct fraction add_frac(struct fraction a, struct fraction b);
struct fraction sub_frac(struct fraction a, struct fraction b);
struct fraction mult_frac(struct fraction a, struct fraction b);
struct fraction div_frac(struct fraction a, struct fraction b);
