#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cnt1 = m-1;
        int cnt2 = n-1;
        for (int i = n + m - 1; i >= 0; i--) {
            if (cnt2 == -1) break;
            if (cnt1 == -1) {
                nums1[i] = nums2[cnt2--];
                continue;
            }

            if (nums1[cnt1] >= nums2[cnt2])
                nums1[i] = nums1[cnt1--];
            else
                nums1[i] = nums2[cnt2--];
        }
    }
};