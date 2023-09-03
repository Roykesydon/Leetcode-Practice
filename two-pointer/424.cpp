#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   private:
    map<char, int> count;

   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int lPtr, rPtr, maxCount, ans;

        ans = 0;
        lPtr = 0;
        rPtr = 0;
        maxCount = 0;

        while (rPtr < n) {
            int rPtrCharCount = ++count[s[rPtr]];

            maxCount = max(maxCount, rPtrCharCount);

            if ((rPtr - lPtr + 1) - maxCount > k) {
                count[s[lPtr]]--;
                maxCount = 0;
                for (auto i : count) maxCount = max(maxCount, i.second);
                lPtr++;
            }

            ans = max(ans, rPtr - lPtr + 1);
            rPtr++;
        }

        return ans;
    }
};