#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<vector<bool>>>
        dp;  // dp[i][j][k]: whether substring that length is <k> in s1 with index i can
             // make substring in s2 with index j with scrambling

    bool isScramble(string s1, string s2) {
        int stringLength = s1.size();

        dp.resize(stringLength);
        for (int i = 0; i < dp.size(); i++) dp[i].resize(stringLength);

        for (int i = 0; i < dp.size(); i++)
            for (int j = 0; j < dp[0].size(); j++)
                dp[i][j].resize(stringLength + 1, false);

        for (int len = 1; len <= stringLength; len++)
            for (int i = 0; i <= stringLength - len; i++)
                for (int j = 0; j <= stringLength - len; j++) {
                    if (len == 1)
                        dp[i][j][1] = s1[i] == s2[j];
                    else if (len > 1) {
                        for (int k = 1; k < len; k++) {
                            if ((dp[i][j][k] && dp[i + k][j + k][len - k]) ||
                                (dp[i + k][j][len - k] &&
                                 dp[i][j + len - k][k]))
                                dp[i][j][len] = true;
                        }
                    }
                }

        return dp[0][0][stringLength];
    }
};