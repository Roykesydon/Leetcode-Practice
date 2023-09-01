#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size() - 1;
        int last = nums.back();
        long long ans = 0;

        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] <= last) {
                last = nums[i];
                continue;
            }

            int x = (nums[i] / last);
            if (nums[i] % last) x++;

            ans += x - 1;

            last = nums[i] / x;
        }

        return ans;
    }
};