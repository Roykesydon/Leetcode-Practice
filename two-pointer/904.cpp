#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   private:
    unordered_map<int, int> cnt;

   public:
    int totalFruit(vector<int>& fruits) {
        int l = 0;
        int r = 0;
        int n = fruits.size();
        int type = 0;
        int ans = 0;

        while (r < n) {
            int rVal = fruits[r];
            cnt[rVal]++;
            if (cnt[rVal] == 1) type++;

            while (type > 2) {
                int lVal = fruits[l];
                cnt[lVal]--;

                if (cnt[lVal] == 0) type--;
                l++;
            }

            ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }
};