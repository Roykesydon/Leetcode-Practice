#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    int cnt1[7];
    int cnt2[7];
    int sum1;
    int sum2;

   public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;

        for (auto i : nums1) cnt1[i]++;
        for (auto i : nums2) cnt2[i]++;

        for (int i = 0; i <= 6; i++) {
            sum1 += cnt1[i] * i;
            sum2 += cnt2[i] * i;
        }

        if (sum2 < sum1) {
            swap(sum1, sum2);
            swap(cnt1, cnt2);
        }

        if (max(nums2.size(), nums1.size()) >
            6 * min(nums1.size(), nums2.size()))
            return -1;

        if (sum1 == sum2) return 0;

        // always true
        if (sum1 < sum2) {
            for (int i = 1; i < 6; i++) {
                if (cnt1[i]) {
                    if (cnt1[i] * (6 - i) >= sum2 - sum1) {
                        for (int j = 1; j <= cnt1[i]; j++) {
                            if (j * (6 - i) >= sum2 - sum1) {
                                return ans + j;
                            }
                        }
                    } else {
                        sum1 += cnt1[i] * (6 - i);
                        ans += cnt1[i];
                        cnt1[6] += cnt1[i];
                        cnt1[i] = 0;
                    }
                }
                if (cnt2[6 - i + 1]) {
                    if (cnt2[6 - i + 1] * (6 - i) >= sum2 - sum1) {
                        for (int j = 1; j <= cnt2[6 - i + 1]; j++) {
                            if (j * (6 - i) >= sum2 - sum1) {
                                return ans + j;
                            }
                        }
                    } else {
                        sum2 -= cnt2[6 - i + 1] * (6 - i);
                        ans += cnt2[6 - i + 1];
                        cnt2[1] += cnt2[6 - i + 1];
                        cnt2[6 - i + 1] = 0;
                    }
                }
            }
        }

        return -2;
    }
};