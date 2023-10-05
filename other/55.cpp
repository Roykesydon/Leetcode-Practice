#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<bool> dp;

   public:
    bool canJump(vector<int>& nums) {
        if (nums[0] == 0) {
            return nums.size() == 1;
        }

        bool flag = true;

        int n = nums.size();
        int cnt = nums[0] - 1;

        for (int i = 1; i < n; i++) {
            if (cnt < 0) {
                flag = false;
                break;
            }
            cnt = max(nums[i] - 1, cnt - 1);
        }

        return flag;
    }
};