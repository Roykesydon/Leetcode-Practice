#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<vector<int>> dp;

   public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        dp.resize(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = 1;
                else if (i + 1 == j) {
                    if (s[i] == s[j]) dp[i][j] = 1;
                } else {
                    if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1];
                }

                ans += dp[i][j];
            }
        }

        return ans;
    }
};