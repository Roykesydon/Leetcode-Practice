#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   private:
    unordered_map<int, unordered_set<int>>
        dp;  // dp[i][j] mean frog can jump to ith position with k units

   public:
    bool canCross(vector<int>& stones) {
        for (int i = 0; i < stones.size(); i++)
            dp[stones[i]] = (unordered_set<int>());

        dp[0].insert(0);

        for (int i = 0; i < stones.size(); i++) {
            for (int j : dp[stones[i]]) {
                for (int k : {-1, 0, 1}) {
                    int nextJump = j + k;

                    if (dp.count(stones[i] + nextJump)) {
                        dp[stones[i] + nextJump].insert(nextJump);
                    }
                }
            }
        }

        if (dp[stones.back()].size()) {
            return true;
        }

        return false;
    }
};