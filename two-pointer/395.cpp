#include <iostream>

using namespace std;

class Solution {
   public:
    int longestSubstring(string s, int k) {
        int count[26];
        int leftPtr = 0, rightPtr = 0;
        int characterKinds;
        int kindsGreaterThanK;
        int ans = 0;

        // iterate all possible counts of character's kinds for answer
        for (int i = 1; i <= 26; i++) {
            characterKinds = 0;
            kindsGreaterThanK = 0;
            leftPtr = 0, rightPtr = -1;
            for (int j = 0; j < 26; j++) count[j] = 0;

            while (rightPtr < int(s.size())) {
                rightPtr++;
                if (rightPtr < int(s.size())) {
                    int index = s[rightPtr] - 'a';
                    count[index]++;

                    if (count[index] == 1) characterKinds++;
                    if (count[index] == k) kindsGreaterThanK++;
                }

                while (characterKinds > i) {
                    int index = s[leftPtr] - 'a';
                    count[index]--;

                    if (count[index] == 0) characterKinds--;
                    if (count[index] == k - 1) kindsGreaterThanK--;

                    leftPtr++;
                }

                if (characterKinds == kindsGreaterThanK) {
                    ans = max(ans,
                              min(rightPtr, int(s.size()) - 1) - leftPtr + 1);
                }
            }
        }

        return ans;
    }
};