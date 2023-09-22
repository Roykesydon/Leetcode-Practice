#include <iostream>
#include <vector>

using namespace std;

class Solution {
   private:
    vector<int> dp;
    vector<int> arr;
    int n;

    int solve(int index) {
        cout << index << '\n';
        if (dp[index] != -1) return dp[index];

        int left = 0;
        int val = arr[index];
        int right = 0;

        if (index) left = arr[index - 1];
        if (index != n - 1) right = arr[index + 1];

        // increasing
        if (index && left < val && index != n - 1 &&
            val < right) {
            dp[index] = solve(index - 1) + 1;
            return dp[index];
        }
        if ((index == 0 || (index && left == val)) &&
            index != n - 1 && val < right) {
            dp[index] = 1;
            return dp[index];
        }
        if ((index == n - 1 ||
             (index != n - 1 && right == val)) &&
            index && left < val) {
            dp[index] = solve(index - 1) + 1;
            return dp[index];
        }

        // decreasing
        if (index && left > val && index != n - 1 &&
            val > right) {
            dp[index] = solve(index + 1) + 1;
            return dp[index];
        }
        if ((index == 0 || (index && left == val)) &&
            index != n - 1 && val > right) {
            dp[index] = solve(index + 1) + 1;
            return dp[index];
        }
        if ((index == n - 1 ||
             (index != n - 1 && right == val)) &&
            index && left > val) {
            dp[index] = 1;
            return dp[index];
        }

        // peak
        if (index && left < val && index != n - 1 &&
            val > right) {
            dp[index] = max(solve(index - 1), solve(index + 1)) + 1;
            return dp[index];
        }

        // valley
        if (index && left > val && index != n - 1 &&
            val < right) {
            dp[index] = 1;
            return dp[index];
        }

        // other
        return dp[index] = 1;
    }

   public:
    int candy(vector<int>& ratings) {
        int ans = 0;

        n = ratings.size();
        arr = ratings;
        dp.resize(n, -1);

        for (int i = 0; i < n; i++) solve(i);

        for (int i = 0; i < n; i++) ans += dp[i];

        return ans;
    }
};