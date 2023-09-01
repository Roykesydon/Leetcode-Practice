#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<int>> dp;

   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vector<int>(n, 0));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k++) {
                    int left = (k == i) ? 0 : dp[i][k - 1];
                    int right = (k == j) ? 0 : dp[k + 1][j];
                    int lastBalloon = nums[k];
                    if (i) lastBalloon *= nums[i - 1];
                    if (j != n - 1) lastBalloon *= nums[j + 1];
                    dp[i][j] = max(dp[i][j], left + lastBalloon + right);
                }
            }
        }

        return dp[0][n - 1];
    }
};