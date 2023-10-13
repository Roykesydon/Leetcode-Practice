#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> dp;

   public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount + 1, -1);
        dp[0] = 0;
        for (int coin : coins)
            for (int i = coin; i <= amount; i++)
                if (dp[i] == -1) {
                    if (dp[i - coin] != -1) dp[i] = dp[i - coin] + 1;
                } else {
                    if (dp[i - coin] != -1)
                        dp[i] = min(dp[i], dp[i - coin] + 1);
                }

        return dp[amount];
    }
};