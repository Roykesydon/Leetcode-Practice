#include <iostream>
using namespace std;
class Solution {
   public:
    int longestContinuousSubstring(string s) {
        int ans = 1;
        int cur = 1;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1] + 1)
                cur++;
            else
                cur = 1;

            ans = max(ans, cur);
        }

        return ans;
    }
};