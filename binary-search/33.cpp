#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l, r, mid, pivot;
        int n = nums.size();

        // find pivot
        l = 0;
        r = n - 1;

        while (l < r) {
            mid = (l + r) / 2;

            if (nums[mid] <= nums[l] && nums[mid] <= nums[r]) {
                r = mid;
            } else if (nums[mid] >= nums[l] && nums[mid] <= nums[r]) {
                r = mid;
            } else if (nums[mid] >= nums[l] && nums[mid] >= nums[r]) {
                l = mid + 1;
            } else {
                l = mid + 1;
            }
        }

        pivot = r;

        cout << r << '\n';

        // find ans
        l = 0;
        r = n - 1;

        while (l < r) {
            mid = (l + r) / 2;

            int midValue = nums[(mid + pivot) % n];

            if (midValue >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (nums[(r+pivot)%n] != target) return -1;

        return (r+pivot)%n;
    }
};