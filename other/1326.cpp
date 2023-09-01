#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> jump;

   public:
    int minTaps(int n, vector<int>& ranges) {
        int farthestCanReach = -1;
        int lastFarthestCanReach = -1;
        int ans = 0;

        jump.resize(n + 1, -1);
        for (int i = 0; i <= n; i++) {
            if (ranges[i] == 0) continue;

            int left = max(0, i - ranges[i]);
            int right = min(
                n - 1,
                i + ranges[i] -
                    1);  // need to see garden as a group of continous segments
            jump[left] = max(jump[left], right);
        }

        for (int i = 0; i < n; i++) {
            farthestCanReach = max(farthestCanReach, jump[i]);
            if (i > lastFarthestCanReach) {
                lastFarthestCanReach = farthestCanReach;
                ans++;
            }

            if (i > farthestCanReach) return -1;
        }

        return ans;
    }
};