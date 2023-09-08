#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int ansLeft = -1;
        int ansRight = -1;

        auto start = upper_bound(nums.begin(), nums.end(), target - 1);
        if (start != nums.end() && *start == target) {
            ansLeft = start - nums.begin();
        }

        auto end = upper_bound(nums.begin(), nums.end(), target);
        if (end != nums.begin()) {
            end--;
            if (*end == target) ansRight = end - nums.begin();
        }

        ans.push_back(ansLeft);
        ans.push_back(ansRight);

        return ans;
    }
};





