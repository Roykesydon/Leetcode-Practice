#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    long long gcd(long long a, long long b) {
        return (b == 0) ? (a) : (gcd(b, a % b));
    }

    long long lcm(long long a, long long b) { return a * b / gcd(a, b); }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long l = 1, r = 2e9;
        while (l < r) {
            long long mid = (l + r) / 2;

            long long num_factor = mid / a + mid / b + mid / c -
                                   mid / lcm(a, b) - mid / lcm(a, c) -
                                   mid / lcm(b, c) + mid / lcm(a, lcm(b, c));

            if (num_factor >= n)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};