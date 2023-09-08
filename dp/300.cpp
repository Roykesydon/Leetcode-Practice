#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> lis;

   public:
    int lengthOfLIS(vector<int>& nums) {
        for (int num : nums) {
            if (lis.empty() || num > lis.back()) {
                lis.push_back(num);
                continue;
            }

            *lower_bound(lis.begin(), lis.end(), num) = num;
        }
        return lis.size();
    }
};