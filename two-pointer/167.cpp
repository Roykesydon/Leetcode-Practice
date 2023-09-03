#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int rPtr, lPtr;
        vector<int> ans;
        rPtr = numbers.size() - 1;
        lPtr = 0;

        while (lPtr < rPtr) {
            int val = numbers[lPtr] + numbers[rPtr];
            if (val == target) break;
            else if (val < target) lPtr++;
            else if (val > target) rPtr--;
        }

        ans.push_back(lPtr + 1);
        ans.push_back(rPtr + 1);

        return ans;
    }
};