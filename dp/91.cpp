#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> dp;
    int dfs(int index, string &s) {
        if (index == s.size()) return 1;

        // memorize
        if (dp[index] != -1) {
            return dp[index];
        }

        int ans = 0;
        // get one number
        if (s[index] != '0') {
            ans += dfs(index + 1, s);
        }

        // get two number
        if (index + 1 < s.size() && s[index] != '0') {
            int val = (s[index] - '0') * 10 + (s[index + 1] - '0');
            if (val <= 26) ans += dfs(index + 2, s);
        }

        return dp[index] = ans;
    }

   public:
    int numDecodings(string s) {
        dp.resize(s.size(), -1);
        return dfs(0, s);
    }
};