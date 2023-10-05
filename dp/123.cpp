#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> dp;

   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int low = 1e9;
        int high = -1e9;
        int ans = 0;

        dp.resize(n, 0);

        for (int i = 0; i < n; i++) {
            dp[i] = max(dp[i], prices[i] - low);
            if(i)
                dp[i] = max(dp[i], dp[i-1]);
            ans = max(ans, dp[i]);
            low = min(low, prices[i]);
        }

        for (int i = n - 1; i > 0; i--) {
            ans = max(ans, high - prices[i] + dp[i-1]);
            high = max(high, prices[i]);
        }

        return ans;
    }
};