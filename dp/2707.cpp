#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   private:
    map<string, bool> dict;
    vector<int> dp;
    int solve(string& s, int index) {
        int ans = 1e9;
        string curString = "";

        if (index == s.size()) return 0;

        if (dp[index] != -1) {
            return dp[index];
        }

        for (int i = index; i < s.size(); i++)
            ans = min(ans, i - index + 1 + solve(s, i + 1));

        for (int i = index; i < s.size(); i++) {
            curString += s[i];
            if (dict.count(curString)) {
                ans = min(ans, solve(s, i + 1));
            }
        }

        return dp[index] = ans;
    }

   public:
    int minExtraChar(string s, vector<string>& dictionary) {
        for (auto i : dictionary) dict[i] = true;
        dp.resize(s.size(), -1);
        return solve(s, 0);
    }
};