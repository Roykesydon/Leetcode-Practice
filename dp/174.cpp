#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<int>> dp;

   public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int INF = 1e9;

        dp.resize(n + 1, vector<int>(m + 1, INF));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) {
                    dp[i][j] =
                        (dungeon[i][j] >= 0) ? (1) : (abs(dungeon[i][j]) + 1);
                    continue;
                }

                int down = dp[i + 1][j];
                int right = dp[i][j + 1];
                dp[i][j] = min(down, right) - dungeon[i][j];

                if (dp[i][j] <= 0) dp[i][j] = 1;
            }
        }

        return dp[0][0];
    }
};