#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int index = 0;
        k %= n;
        if (k == 0) return;
        while (true) {
            bool flag = true;
            if (k == 0) break;
            while (n - k >= k) {
                for (int i = n - 1; i >= n - k; i--)
                    swap(nums[index + i], nums[index + i - k]);
                n -= k;
                flag = false;
            }
            while (n - k <= k) {
                if (n - k == 0 || k == 0) break;
                for (int i = 0; i < n - k; i++)
                    swap(nums[i + index], nums[index + i + n - k]);
                int tmp = n - k;
                index += tmp;
                n -= tmp;
                k -= tmp;
                flag = false;
            }

            if (flag) break;
        }
    }
};