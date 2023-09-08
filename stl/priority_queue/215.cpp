#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   private:
    class CompareLess {
       public:
        bool operator()(int a, int b) { return a > b; }
    };
    priority_queue<int, vector<int>, CompareLess> pq;

   public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int num : nums) {
            pq.push(num);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};