#include <iostream>

#define ll long long

using namespace std;

class Solution {
   private:
    ll combination(ll x, ll y) {
        y = min(y, x - y);

        ll tmp = 1;

        for (ll i = 1; i <= y; i++) {
            tmp *= x - i + 1;
            tmp /= i;
        }

        return tmp;
    }

   public:
    int climbStairs(int n) {
        ll ans = 0;
        for (int i = 0; i < n && n - i >= i; i++) ans += combination(n - i, i);

        return ans;
    }
};