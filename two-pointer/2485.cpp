#include <iostream>

using namespace std;

class Solution {
   public:
    int pivotInteger(int n) {
        int l = 1;
        int r = n;
        int lSum = 1;
        int rSum = n;

        if (n == 1)
            return n;
        else if (n == 2)
            return -1;

        while (l < r) {
            r--;
            rSum += r;

            while (lSum < rSum && l < r) {
                l++;
                lSum += l;
            }

            if (r == l && rSum == lSum) return r;
        }

        return -1;
    }
};