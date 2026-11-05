int gcd(int m, int n)
{
     int temp;

     if (m < n) {
         temp = m;
         m = n;
         n = temp;
     }

     while (m) {
         temp = m;
         m = n % m;
         n = temp;
     }

     return n;
}

