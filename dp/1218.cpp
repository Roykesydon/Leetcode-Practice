#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   private:
    unordered_map<int, int> dp;

   public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        for (int num : arr) {
            dp[num] = max(dp[num], dp[num - difference] + 1);
            ans = max(ans, dp[num]);
        }

        return ans;
    }
};