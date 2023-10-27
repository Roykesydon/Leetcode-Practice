#include <iostream>
#include <vector>

#define ll long long
#define MOD 1000000007

using namespace std;

class Solution {
   private:
    ll dp[1005][3];
    ll solve(int x, int status) {
        if (x < 0) return 0;
        if (x == 0 && status == 0) return 1;
        if (dp[x][status] != -1) return dp[x][status];

        ll ans = 0;
        if (status == 0) {
            ans += solve(x - 1, 0);
            ans += solve(x - 2, 0);
            ans += solve(x - 1, 1);
            ans += solve(x - 1, 2);
        } else if (status == 1) {  // up empty
            ans += solve(x - 1, 2);
            ans += solve(x - 2, 0);
        } else if (status == 2) {  // bottom empty
            ans += solve(x - 1, 1);
            ans += solve(x - 2, 0);
        }

        return dp[x][status] = ans % MOD;
    }

   public:
    int numTilings(ll n) {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 3; j++) dp[i][j] = -1;

        return solve(n, 0);
    }
};