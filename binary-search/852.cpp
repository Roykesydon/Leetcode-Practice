#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l, r, mid;
        int n = arr.size();

        l = 0;
        r = n - 1;

        while (l < r) {
            mid = (l + r) / 2;

            int leftMidValue = -1;
            int rightMidValue = -1;
            int midValue = arr[mid];

            if (mid) leftMidValue = arr[mid - 1];
            if (mid + 1 < n) rightMidValue = arr[mid + 1];

            if (leftMidValue == -1) {
                if (rightMidValue < midValue)
                    r = mid;
                else
                    l = mid;

            } else if (rightMidValue == -1) {
                if (leftMidValue > midValue)
                    r = mid;
                else
                    l = mid;
            } else {
                if (rightMidValue < midValue && leftMidValue < midValue)
                    return mid;
                else if (rightMidValue > midValue) {
                    l = mid;
                } else if (rightMidValue < midValue) {
                    r = mid;
                }
            }
        }

        return mid;
    }
};