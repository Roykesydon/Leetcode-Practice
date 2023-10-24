#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    int dp[3];

   public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            int cur = i%3;
            int tmp1 = ((i-1>=0)?dp[(cur+2)%3]:0);
            int tmp2 = ((i-2>=0)?dp[(cur+1)%3]:0);
            dp[cur] = max(tmp1, tmp2 + nums[i]);
        }

        return dp[(n-1)%3];
    }
};