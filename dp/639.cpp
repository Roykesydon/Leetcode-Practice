#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

class Solution {
   private:
    vector<long long> dp;
    long long dfs(int index, string &s) {
        if (index == s.size()) return 1;

        // memorize
        if (dp[index] != -1) {
            return dp[index];
        }

        long long ans = 0;
        // get one number
        if (s[index] != '0') {
            if (s[index] == '*')
                ans += 9 * dfs(index + 1, s);
            else
                ans += dfs(index + 1, s);
        }
        ans %= MOD;

        // get two number
        if (index + 1 < s.size() && s[index] != '0') {
            if (s[index] == '*' && s[index + 1] == '*') {
                ans += (9 + 6) * dfs(index + 2, s);
            } else if (s[index] != '*' && s[index + 1] == '*') {
                if (s[index] == '1') {
                    ans += 9 * dfs(index + 2, s);
                } else if (s[index] == '2') {
                    ans += 6 * dfs(index + 2, s);
                }
            } else if (s[index] == '*' && s[index + 1] != '*') {
                if (s[index + 1] - '0' <= 6) {
                    ans += 2 * dfs(index + 2, s);
                } else {
                    ans += dfs(index + 2, s);
                }

            } else {
                int val = (s[index] - '0') * 10 + (s[index + 1] - '0');
                if (val <= 26) ans += dfs(index + 2, s);
            }
        }
        ans %= MOD;

        return dp[index] = ans;
    }

   public:
    int numDecodings(string s) {
        dp.resize(s.size(), -1);
        return dfs(0, s);
    }
};