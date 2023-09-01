#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> prefixSum;

   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans;
        prefixSum.resize(n + 1);
        prefixSum[0] = 0;
        for (int i = 1; i <= n; i++)
            prefixSum[i] = prefixSum[i - 1] + cardPoints[i - 1];

        // all right
        ans = prefixSum[n] - prefixSum[n - k];

        for (int i = 1; i <= k; i++) {
            int x = 0;
            // left
            x += prefixSum[i];

            // right
            x += prefixSum[n] - prefixSum[n - (k - i)];

            ans = max(ans, x);
        }

        return ans;
    }
};