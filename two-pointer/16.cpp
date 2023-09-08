#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
   public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int minDiff = 1e9;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int total = nums[i] + nums[j] + nums[k];
                if (abs(total - target) < minDiff) {
                    minDiff = abs(total - target);
                    ans = total;
                };
                if (total > target) k--;
                else if (total < target) j++;
                else if(total == target) break;
            }
        }

        return ans;
    }
};