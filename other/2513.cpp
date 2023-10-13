#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

class Solution {
   private:
    ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

    bool canSolve(ll x, int divisor1, int divisor2, int uniqueCnt1,
                  int uniqueCnt2) {
        ll lcmDivide = lcm((ll)divisor1, (ll)divisor2);
        ll lcmCnt = x / lcmDivide;
        uniqueCnt2 -= min((x / divisor1 - lcmCnt), (ll)uniqueCnt2);

        uniqueCnt1 -= min((x / divisor2 - lcmCnt), (ll)uniqueCnt1);

        return (x - (x / divisor1 + x / divisor2 - lcmCnt)) >=
               uniqueCnt1 + uniqueCnt2;
    }

   public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1,
                    int uniqueCnt2) {
        ll l = 0;
        ll r = 1e12;
        ll mid;

        while (l < r) {
            mid = (l + r) / 2;

            if (canSolve(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};