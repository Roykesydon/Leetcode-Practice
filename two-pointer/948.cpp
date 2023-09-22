#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int l = 0, r = n - 1;
        int ans = 0;
        int score = 0;

        sort(tokens.begin(), tokens.end());

        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l];
                score++;
                l++;
                ans = max(ans, score);
            } else {
                if (score == 0) break;
                
                power += tokens[r];
                score--;
                r--;
            }
        }

        return ans;
    }
};