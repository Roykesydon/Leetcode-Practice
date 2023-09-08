#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    class MaxValue {
       public:
        int val;
        int index;
        MaxValue(int val_, int index_) {
            val = val_;
            index = index_;
        }
    };

    deque<MaxValue> deq;

   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            while (!deq.empty() && i - deq.front().index >= k) deq.pop_front();
            while (!deq.empty() && deq.back().val < nums[i]) deq.pop_back();
            deq.push_back(MaxValue(nums[i], i));

            if (i >= (k - 1)) ans.push_back(deq.front().val);
        }

        return ans;
    }
};