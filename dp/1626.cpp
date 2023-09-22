#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> dp;
    vector<pair<int, int>> arr;

   public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        int ans = 0;

        dp.resize(n, 0);

        for (int i = 0; i < n; i++) arr.push_back({ages[i], scores[i]});

        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) dp[i] = arr[i].second;

        for (int i = 1; i < n; i++){
            for (int j = 0; j < i; j++) {
                if (arr[i].first == arr[j].first) {
                    dp[i] = max(dp[i], dp[j] + arr[i].second);
                }
                // ages[j] < ages[i]
                else if (arr[j].second <= arr[i].second)
                    dp[i] = max(dp[i], dp[j] + arr[i].second);
            }
        }

        for (int i = 0; i < n; i++) ans = max(ans, dp[i]);

        return ans;
    }
};