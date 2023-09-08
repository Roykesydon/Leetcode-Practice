#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> dp;
    int ans;

   public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;

        dp.resize(amount + 1, 0);
        ans = 0;
        dp[0] = 1;

        for (int coin : coins)
            for (int i = coin; i <= amount; i++) dp[i] += dp[i - coin];

        return dp[amount];
    }
};