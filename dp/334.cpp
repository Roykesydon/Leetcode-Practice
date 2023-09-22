#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            if (ans.empty() || (!ans.empty() && num > ans.back()))
                ans.push_back(num);
            else
                *lower_bound(ans.begin(), ans.end(), num) = num;

            if (ans.size() >= 3) return true;
        }

        return false;
    }
};