#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   private:
    map<int, int> count;
    vector<int> dp;
    int solve(int index, vector<int>& uniqueNums) {
        if (index == uniqueNums.size()) return 0;

        if (dp[index] != -1) return dp[index];

        int ans = 0;
        int currentValue = uniqueNums[index];

        // if not the last one
        if (index != uniqueNums.size() - 1) {
            // choose this one
            if (currentValue + 1 == uniqueNums[index + 1]) {
                ans = max(ans, count[currentValue] * currentValue +
                                   solve(index + 2, uniqueNums));
            } else {
                ans = max(ans, count[currentValue] * currentValue +
                                   solve(index + 1, uniqueNums));
            }
        } else {
            ans = max(ans, count[currentValue] * currentValue +
                               solve(index + 1, uniqueNums));
        }

        // abort this one
        ans = max(ans, solve(index + 1, uniqueNums));

        return dp[index] = ans;
    }

   public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i : nums) count[i]++;

        vector<int> uniqueNums = nums;
        uniqueNums.resize(unique(uniqueNums.begin(), uniqueNums.end()) -
                          uniqueNums.begin());

        dp.resize(uniqueNums.size(), -1);

        return solve(0, uniqueNums);
    }
};