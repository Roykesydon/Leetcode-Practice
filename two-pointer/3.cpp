#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   private:
    unordered_map<char, int> vis;

   public:
    int lengthOfLongestSubstring(string s) {
        int l, r;
        int n = s.size();
        int ans = 0;

        l = 0;
        r = 0;
        while (r < n) {
            vis[s[r]]++;
            while (vis[s[r]] > 1) {
                vis[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};