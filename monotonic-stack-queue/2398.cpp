#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    deque<pair<int, int>> dq;  // cost, index

   public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts,
                      long long budget) {
        int n = chargeTimes.size();
        int l = 0;
        int r = 0;
        int ans = 0;
        long long curRunningCost = 0;

        while (r < n) {
            long long cost;
            curRunningCost += runningCosts[r];
            // update ans;
            if (dq.empty()) {
                cost = chargeTimes[r] + runningCosts[r];
            } else {
                cost = max(chargeTimes[r], dq.front().first) +
                       (r - l + 1) * curRunningCost;
            }
            if (cost <= budget) ans = ans = max(ans, r - l + 1);

            // maintain deque
            while (!dq.empty() && dq.back().first <= chargeTimes[r]) {
                dq.pop_back();
            }
            dq.push_back({chargeTimes[r], r});

            while (cost >= budget && l <= r) {
                int lValue = runningCosts[l];
                curRunningCost -= lValue;

                if (dq.front().second == l) {
                    dq.pop_front();
                }
                l++;

                if (dq.empty())
                    cost = (long long)1e18;
                else
                    cost = dq.front().first + (r - l + 1) * curRunningCost;
            }

            // update ans;
            if (cost <= budget) ans = ans = max(ans, r - l + 1);

            r++;
        }

        return ans;
    }
};