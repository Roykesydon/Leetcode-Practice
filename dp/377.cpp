#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<long long> dp;

   public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int MAXN = 1001;
        dp.resize(MAXN, 0);
        dp[0] = 1;

        for (int j = 0; j <= target; j++) {
            for (int num : nums) {
                if (j < num) continue;

                dp[j] += dp[j - num];
                dp[j] %= (long long)1e12;
            }
        }

        return dp[target];
    }
};