#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   private:
    // unordered_map<char, int> count;
    int count[26];

   public:
    int minDeletions(string s) {
        vector<int> tmp;
        int ans = 0;
        int vis = -1;

        for (char ch : s) count[ch - 'a']++;

        for (int i = 0; i < 26; i++)
            if (count[i]) tmp.push_back(count[i]);

        sort(tmp.begin(), tmp.end());

        vis = tmp.back();
        for (int i = tmp.size() - 2; i >= 0; i--) {
            if (vis == 0) {
                ans += tmp[i];
                continue;
            } else if (tmp[i] >= vis) {
                ans += tmp[i] - vis + 1;
                tmp[i] = max(vis - 1, 0);
            }
            vis = tmp[i];
        }

        return ans;
    }
};