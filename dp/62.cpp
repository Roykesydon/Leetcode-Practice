#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> dp;

   public:
    int uniquePaths(int m, int n) {
        dp.resize(m + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) {
                    dp[j] = 1;
                    continue;
                }
                dp[j] = dp[j] + dp[j + 1];
            }
        }

        return dp[0];
    }
};