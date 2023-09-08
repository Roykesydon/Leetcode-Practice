#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
   public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int ans = 0;

        while (l < r) {
            int minHeight = min(height[l], height[r]);
            ans = max(ans, (r - l) * minHeight);
            

            while (height[l] <= minHeight && l < r) l++;
            ans = max(ans, (r - l) * minHeight);
            while (height[r] <= minHeight && l < r) r--;
            ans = max(ans, (r - l) * minHeight);
        }

        return ans;
    }
};